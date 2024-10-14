# Makefile

CXX = g++
CXXFLAGS = -Wall -O2
SOURCES = main.cpp timer.cpp arithmetic_tests.cpp
TARGET = benchmark_tool

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
