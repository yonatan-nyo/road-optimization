# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
BIN_DIR = bin

# Output binary
TARGET = $(BIN_DIR)/main

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Build target (compiles the project)
build: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files in bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean object files only
clean-obj:
	rm -f $(OBJS)

# Clean everything (objects + binary)
clean:
	rm -rf $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Default target (build, clean objects, and run)
all: build clean-obj run