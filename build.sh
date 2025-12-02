#!/bin/bash
# ============================================================================
# build.sh - Linux/Mac Build Script
# ============================================================================
# This script automates the build process on Unix-like systems
# Usage: ./build.sh [clean|test|run]
# ============================================================================

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}=====================================${NC}"
echo -e "${GREEN}  DSA 30-Day Challenge - Build${NC}"
echo -e "${GREEN}=====================================${NC}"

# Check if CMake is installed
if ! command -v cmake &> /dev/null; then
    echo -e "${RED}Error: CMake is not installed!${NC}"
    echo "Please install CMake first:"
    echo "  Ubuntu/Debian: sudo apt-get install cmake"
    echo "  MacOS: brew install cmake"
    exit 1
fi

# Parse command line arguments
BUILD_TYPE="Release"
RUN_TESTS=false
CLEAN_BUILD=false
RUN_LAUNCHER=false

for arg in "$@"; do
    case $arg in
        clean)
            CLEAN_BUILD=true
            ;;
        test)
            RUN_TESTS=true
            ;;
        run)
            RUN_LAUNCHER=true
            ;;
        debug)
            BUILD_TYPE="Debug"
            ;;
        *)
            echo -e "${YELLOW}Unknown option: $arg${NC}"
            ;;
    esac
done

# Clean build if requested
if [ "$CLEAN_BUILD" = true ]; then
    echo -e "${YELLOW}Cleaning build directory...${NC}"
    rm -rf build
fi

# Create build directory
mkdir -p build
cd build

# Configure with CMake
echo -e "${GREEN}Configuring with CMake...${NC}"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..

# Build
echo -e "${GREEN}Building project...${NC}"
cmake --build . --config $BUILD_TYPE -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

echo -e "${GREEN}✓ Build completed successfully!${NC}"

# Run tests if requested
if [ "$RUN_TESTS" = true ]; then
    echo -e "${GREEN}Running tests...${NC}"
    ctest --output-on-failure
fi

# Run launcher if requested
if [ "$RUN_LAUNCHER" = true ]; then
    echo -e "${GREEN}Starting DSA Launcher...${NC}"
    cd ..
    ./build/bin/dsa
else
    echo ""
    echo -e "${GREEN}Executables are in: build/bin/${NC}"
    echo ""
    echo "To run the interactive launcher:"
    echo -e "  ${YELLOW}./build/bin/dsa${NC}"
    echo ""
    echo "To run a specific day:"
    echo -e "  ${YELLOW}./build/bin/day01 < tests/Day01/input.txt${NC}"
    echo ""
    echo "To run tests:"
    echo -e "  ${YELLOW}./build.sh test${NC}"
    echo ""
fi
