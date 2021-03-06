#include <any>
#include <map>
#include <vector>
#include <string>

enum ConvertType {
  ParseInt,
  ParseDouble,
  ParseString
};

class AnyParse {
public:
  AnyParse(){};
  AnyParse(int argc, char** argv);

  template <typename T>
  void SetValue(const std::string &key, T value){ Arguments[key] = value; }

  template <typename T>
  void AddArgument(const std::string &key, T value, const std::string &shortname, 
      int nargs, const std::string help, ConvertType cv)
  {
    this->shortName[shortname] = key;
    this->help[key] = help;
    this->nargs[key] = nargs;
    this->SetValue(key, value);
    this->Conversion[key] = cv;
  }
  
  template <typename T>
  T GetValue(const std::string &key, T defaultValue) const
  {
    auto iterator = this->Arguments.find(key);
    if( iterator == this->Arguments.end() )
      return defaultValue;
    return std::any_cast<T>(iterator->second);
  }


  void Parse();

  // Properties of the argument
  std::vector<std::string> CommandLine;
  std::vector<std::string> Positionals;
  std::map< std::string, ConvertType > Conversion;
  std::map< std::string, std::any > Arguments;
  std::map< std::string, std::string > shortName;
  std::map< std::string, std::string > help;
  std::map< std::string, int > nargs;
};
