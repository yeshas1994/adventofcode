CC = g++
# the compiler: gcc for C program, define as g++ for C++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
TARGET = day01

$(TARGET): $(TARGET).o
	g++ -o $(TARGET) -std=c++17 -Wall $(TARGET).o
$(TARGET).o: $(TARGET).cpp
	g++ -c $(TARGET).cpp
