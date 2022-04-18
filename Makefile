_OBJS := $(patsubst %.cc, %.o, $(wildcard *.cc))
OBJS := $(patsubst %, %, $(_OBJS))
SRC := $(wildcard *.cpp)
EXE := $(patsubst %.cpp, %, $(SRC))

all: $(SRC) $(OBJS) $(EXE)

%: ./%.cpp $(OBJS)
	g++ --std=c++17 -I./ $(OBJS) $@.cpp -o $@

%.o: %.cc
	g++ -I./ --std=c++17 -shared -c -fPIC $*.cc -o $*.o

clean:
	rm -f $(EXE)
	rm -f *.o
