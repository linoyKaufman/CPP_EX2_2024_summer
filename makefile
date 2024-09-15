CXX=g++
CXXFLAGS=-std=c++17 -Wall 
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
HEADERS = tree.hpp complex.hpp node.hpp
TARGET = tree
SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)
TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp = .o)

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_FLAGS)

test: $(TEST_OBJS) $(OBJ)
		$(CXX) $(CXXFLAGS) $^ -o test
		
clean:
	rm -f *.o main test tree


