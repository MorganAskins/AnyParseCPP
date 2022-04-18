#include <AnyParse.hh>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
  AnyParse parser(argc, argv);
  parser.AddArgument("bob", std::vector<double>{1.0, 2.0}, "b", 2, "Ronda", ParseDouble);
  parser.AddArgument("on", false, "o", 0, "Turn on", ParseInt);
  parser.AddArgument("double", 1.0, "d", 1, "doobley", ParseDouble);
  parser.Parse();
  for(auto const [key, value] : parser.Arguments){
    //cout << key << " " << value << endl;
  }
  // Now lets test things
  auto bob = parser.GetValue("bob", std::vector<double>());
  cout << "BOB Says >> " << bob[0] << " - " << bob[1] << endl;
  cout << "The switch is " << parser.GetValue("on", false) << endl;
  cout << "Positional arguments: " << endl;
  for(auto& v : parser.Positionals){
    cout << ">> " << v << endl;
  }
  cout << "Double: " << parser.GetValue("double", double()) << endl;
}
