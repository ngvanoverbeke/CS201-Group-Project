CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = -lcryptopp

# We use this to 
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp) $(wildcard *.h)
OBJECTS = $(patsubst %.cpp,%.o,build/$(SOURCES))

# Write the name of your program here
TARGET = build/out

MKDIR_P = mkdir -p

.PHONY: directories all clean run

# This "phony" target says we want the target to be built
all: directories $(TARGET)

directories:
				${MKDIR_P} build

# This "phony" target removes all built files
clean:
				$(RM) -r build

run: all
				./build/out

# Tells make how to make target out of objects
$(TARGET): $(OBJECTS)
				$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

# Tells make how to make objects out of source code
# It also says when we change a header, recompile
# $< is the input, $@ is the output
build/%.o: %.cpp $(HEADERS)
				$(CXX) $(CXXFLAGS) -c $< -o $@