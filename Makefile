# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./include

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Object files (replace .cpp with .o)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Output file
OUT = WiFiSimulator

# Targets

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OUT)

run: $(OUT)
	./$(OUT)

# Optional: If you want to run tests, you can use this target
test: $(OUT)
	./$(OUT) < test_input.txt > output.txt
