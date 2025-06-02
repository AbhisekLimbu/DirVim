CXX := g++
CXXFLAGS := -wall -Wextra -std=c++17

SRC_DIR := src
BUILd_DIR := build 
BIN = DirVim

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(pathsubst  $(SRC_DIR)/%.cpp, $(BUILD.DIR)/%.o, $(SRCS))

$(BUILD_DIR)/%.o = : $(SRC_DIR)/*.cpp)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
.phony: clean

clean :
	rm -rf $(BUILD_DIR) $(BIN)

