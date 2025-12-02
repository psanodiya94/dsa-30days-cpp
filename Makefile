# Makefile for 30-Day DSA Challenge in C++

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directories
DAYS = $(wildcard Day*)
BUILD_DIR = build

.PHONY: all clean test help

# Default target
all: help

# Help target
help:
	@echo "=================================="
	@echo "  30-Day DSA Challenge - Makefile"
	@echo "=================================="
	@echo ""
	@echo "Available targets:"
	@echo "  make build DAY=XX     - Build solution for specific day (e.g., make build DAY=01)"
	@echo "  make test DAY=XX      - Build and test solution for specific day"
	@echo "  make run DAY=XX       - Build and run solution interactively"
	@echo "  make all-build        - Build all solutions"
	@echo "  make all-test         - Build and test all solutions"
	@echo "  make clean            - Remove all build artifacts"
	@echo "  make help             - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make build DAY=01"
	@echo "  make test DAY=05"
	@echo "  make run DAY=10"
	@echo ""

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Build a specific day's solution
build: $(BUILD_DIR)
ifndef DAY
	@echo "Error: Please specify DAY (e.g., make build DAY=01)"
	@exit 1
endif
	@echo "Building Day$(DAY)..."
	@$(CXX) $(CXXFLAGS) Day$(DAY)/solution.cpp -o $(BUILD_DIR)/day$(DAY)
	@echo "✓ Built successfully: $(BUILD_DIR)/day$(DAY)"

# Test a specific day's solution
test: build
ifndef DAY
	@echo "Error: Please specify DAY (e.g., make test DAY=01)"
	@exit 1
endif
	@echo "Testing Day$(DAY)..."
	@if [ -f tests/Day$(DAY)/input.txt ] && [ -f tests/Day$(DAY)/expected.txt ]; then \
		$(BUILD_DIR)/day$(DAY) < tests/Day$(DAY)/input.txt > $(BUILD_DIR)/day$(DAY)_output.txt; \
		if diff -q $(BUILD_DIR)/day$(DAY)_output.txt tests/Day$(DAY)/expected.txt > /dev/null; then \
			echo "✓ Test passed for Day$(DAY)!"; \
		else \
			echo "✗ Test failed for Day$(DAY)"; \
			echo "Expected:"; \
			cat tests/Day$(DAY)/expected.txt; \
			echo "Got:"; \
			cat $(BUILD_DIR)/day$(DAY)_output.txt; \
		fi \
	else \
		echo "Warning: Test files not found for Day$(DAY)"; \
	fi

# Run a specific day's solution interactively
run: build
ifndef DAY
	@echo "Error: Please specify DAY (e.g., make run DAY=01)"
	@exit 1
endif
	@echo "Running Day$(DAY) (enter input manually or Ctrl+C to exit):"
	@$(BUILD_DIR)/day$(DAY)

# Build all solutions
all-build: $(BUILD_DIR)
	@echo "Building all solutions..."
	@for day in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30; do \
		if [ -f Day$$day/solution.cpp ]; then \
			echo "Building Day$$day..."; \
			$(CXX) $(CXXFLAGS) Day$$day/solution.cpp -o $(BUILD_DIR)/day$$day || exit 1; \
		fi \
	done
	@echo "✓ All solutions built successfully!"

# Test all solutions
all-test: all-build
	@echo "Testing all solutions..."
	@passed=0; \
	failed=0; \
	for day in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30; do \
		if [ -f tests/Day$$day/input.txt ] && [ -f tests/Day$$day/expected.txt ]; then \
			$(BUILD_DIR)/day$$day < tests/Day$$day/input.txt > $(BUILD_DIR)/day$$day_output.txt 2>&1; \
			if diff -q $(BUILD_DIR)/day$$day_output.txt tests/Day$$day/expected.txt > /dev/null 2>&1; then \
				echo "✓ Day$$day passed"; \
				passed=$$((passed + 1)); \
			else \
				echo "✗ Day$$day failed"; \
				failed=$$((failed + 1)); \
			fi \
		fi \
	done; \
	echo ""; \
	echo "Results: $$passed passed, $$failed failed"

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR)
	@echo "✓ Clean complete"

# Show problem for a specific day
problem:
ifndef DAY
	@echo "Error: Please specify DAY (e.g., make problem DAY=01)"
	@exit 1
endif
	@if [ -f Day$(DAY)/problem.md ]; then \
		cat Day$(DAY)/problem.md; \
	else \
		echo "Problem file not found for Day$(DAY)"; \
	fi

# Show explanation for a specific day
explain:
ifndef DAY
	@echo "Error: Please specify DAY (e.g., make explain DAY=01)"
	@exit 1
endif
	@if [ -f Day$(DAY)/explanation.md ]; then \
		cat Day$(DAY)/explanation.md; \
	else \
		echo "Explanation file not found for Day$(DAY)"; \
	fi
