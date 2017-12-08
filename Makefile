CXX := g++
CFLAGS := -ansi -pedantic -Wall -Wextra -std=c++1y
LFLAGS :=
RM := rm -vf
EXE := out
SOURCES = $(wildcard *.cc)
OBJS := $(SOURCES:.cc=.o)

all : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(EXE)

%.o : %.cc
	$(CXX) -c $(CFLAGS) $< -o $@

quick : %.o
	$(CXX) -c $(CFLAGS) main.cc
	$(CXX) $(LFLAGS) *.o -o $(EXE)

clean :
	$(RM) $(EXE) $(OBJS) a.out

exam :
	for i in *.cc; do g++ -ansi -pedantic -Wall -Wextra -std=c++1y $$i -c; done
	g++ *.o
