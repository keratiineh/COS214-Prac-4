CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g
TARGET := taskforge 

SOURCES := $(wildcard *.cpp)

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: all clean 