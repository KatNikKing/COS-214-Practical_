CXX := g++
CXXFLAGS = -std=c++11 -g

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := eventflow

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./eventflow

val: $(TARGET)
	valgrind --leak-check=full --keep-stacktraces=alloc-and-free --track-origins=yes ./eventflow

clean:
	rm -f $(OBJS) $(TARGET)
