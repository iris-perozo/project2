SOURCES := main.cpp
# Objs are all the sources, with .cpp replaced by .o
OBJS := $(SOURCES:.cpp=.o)

all: main

# Compile the binary 'main' by calling the compiler with cflags, lflags, and any libs (if defined) and the list of objects.
main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) $(LFLAGS) $(LIBS)

# Get a .o from a .cpp by calling compiler with cflags and includes (if defined)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

run: main
	./main