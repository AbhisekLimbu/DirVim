CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude
LDLIBS := -lncurses
SRC_DIR := src
BUILD_DIR := build
BIN := DirVim

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)


.PHONY: clean

clean:
	@rm -rf $(BUILD_DIR) $(BIN)
