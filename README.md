# 🚀 30-Day DSA Challenge in C++

A comprehensive 30-day Data Structures and Algorithms learning journey with C++17. Master essential DSA concepts through curated problems with detailed explanations, optimized solutions, and test cases.

**✨ New Features:**
- 🪟 **Windows GUI** - Interactive graphical interface for Windows users
- 🐧 **Linux CLI** - Terminal-based interactive launcher for Linux users
- 🔧 **CMake Build System** - Cross-platform build support (Windows + Linux)
- 📝 **Extensive Comments** - Detailed explanations in every solution file
- 🎯 **Visual Studio Support** - Native Visual Studio 2022/2026 solution with project files for seamless IDE integration

## 📚 Table of Contents

- [Overview](#overview)
- [Platform Support](#platform-support)
- [Project Structure](#project-structure)
- [Topics Covered](#topics-covered)
- [Daily Curriculum](#daily-curriculum)
- [Quick Start](#quick-start)
  - [Windows (GUI)](#windows-gui)
  - [Linux/Mac (CLI)](#linuxmac-cli)
- [Building from Source](#building-from-source)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)

## 🎯 Overview

This repository contains a structured 30-day learning path covering fundamental to advanced data structures and algorithms. Each day includes:

- **Problem Statement** (`problem.md`) - Clear problem description with examples and constraints
- **Detailed Explanation** (`explanation.md`) - Approach, intuition, complexity analysis, and walkthroughs
- **Optimized Solution** (`solution.cpp`) - Clean, extensively commented C++17 implementation
- **Test Cases** (`tests/DayXX/`) - Sample inputs and expected outputs

## 🖥️ Platform Support

| Platform | Build System | Interface | Status |
|----------|--------------|-----------|--------|
| Windows 10/11 | CMake + Visual Studio | **GUI Application** | ✅ Fully Supported |
| Linux | CMake + GCC/Clang | CLI Launcher | ✅ Fully Supported |
| macOS | CMake + Clang | CLI Launcher | ✅ Fully Supported |

## 📁 Project Structure

```
dsa-30days-cpp/
│
├── src/
│   ├── Day01/ - Day30/      # Daily challenges (organized in src)
│   │   ├── problem.md       # Problem statement
│   │   ├── explanation.md   # Detailed explanation
│   │   └── solution.cpp     # Extensively commented solution
│   │
│   ├── windows_gui/         # Windows GUI application
│   │   ├── main.cpp         # GUI implementation
│   │   └── resource.rc      # Windows resources
│   │
│   └── cli_launcher/        # Linux CLI launcher
│       └── main.cpp         # Terminal interface
│
├── tests/                   # Test cases for all days
│   └── DayXX/
│       ├── input.txt        # Test input
│       └── expected.txt     # Expected output
│
├── CMakeLists.txt           # Main CMake configuration
├── build.sh                 # Linux build script
├── build.bat                # Windows build script
├── Makefile                 # Legacy Make support (Linux)
├── SETUP_GUIDE.md           # Quick start guide
└── README.md                # This file
```
## 🎓 Topics Covered

### Core Data Structures
- ✅ Arrays & Strings
- ✅ Hash Tables & Hash Maps
- ✅ Linked Lists
- ✅ Stacks & Queues
- ✅ Trees (Binary Trees, BST)
- ✅ Heaps (Priority Queues)
- ✅ Graphs

### Essential Algorithms
- ✅ Two Pointers
- ✅ Sliding Window
- ✅ Binary Search
- ✅ Depth-First Search (DFS)
- ✅ Breadth-First Search (BFS)
- ✅ Dynamic Programming (1D & 2D)
- ✅ Greedy Algorithms
- ✅ Backtracking
- ✅ Topological Sort
- ✅ Bit Manipulation

## 📅 Daily Curriculum

### Week 1: Foundations
| Day | Problem | Topics | Difficulty |
|-----|---------|--------|------------|
| 01 | Two Sum | Arrays, Hash Table | Easy |
| 02 | Best Time to Buy and Sell Stock | Arrays, DP, Greedy | Easy |
| 03 | Maximum Subarray | Arrays, DP (Kadane's) | Medium |
| 04 | Product of Array Except Self | Arrays, Prefix Sum | Medium |
| 05 | Container With Most Water | Arrays, Two Pointers | Medium |
| 06 | Valid Anagram | Strings, Hash Table | Easy |
| 07 | Longest Substring Without Repeating Characters | Strings, Sliding Window | Medium |

### Week 2: Strings & Advanced Arrays
| Day | Problem | Topics | Difficulty |
|-----|---------|--------|------------|
| 08 | Longest Palindromic Substring | Strings, DP | Medium |
| 09 | Group Anagrams | Strings, Hash Table | Medium |
| 10 | Top K Frequent Elements | Hashing, Heaps | Medium |
| 11 | Valid Palindrome | Two Pointers, Strings | Easy |
| 12 | 3Sum | Two Pointers, Sorting | Medium |
| 13 | Minimum Window Substring | Sliding Window | Hard |
| 14 | Longest Repeating Character Replacement | Sliding Window | Medium |

### Week 3: Linear Data Structures & Trees
| Day | Problem | Topics | Difficulty |
|-----|---------|--------|------------|
| 15 | Reverse Linked List | Linked List, Recursion | Easy |
| 16 | Merge Two Sorted Lists | Linked List | Easy |
| 17 | Valid Parentheses | Stack, Strings | Easy |
| 18 | Implement Queue using Stacks | Stack, Queue, Design | Easy |
| 19 | Binary Tree Inorder Traversal | Trees, DFS | Easy |
| 20 | Binary Tree Level Order Traversal | Trees, BFS | Medium |
| 21 | Maximum Depth of Binary Tree | Trees, DFS/BFS | Easy |

### Week 4: Search, Graphs & Dynamic Programming
| Day | Problem | Topics | Difficulty |
|-----|---------|--------|------------|
| 22 | Binary Search | Arrays, Binary Search | Easy |
| 23 | Search in Rotated Sorted Array | Binary Search | Medium |
| 24 | Kth Largest Element in an Array | Heaps, Quickselect | Medium |
| 25 | Number of Islands | Graphs, DFS/BFS | Medium |
| 26 | Course Schedule | Graphs, Topological Sort | Medium |
| 27 | Climbing Stairs | DP (1D) | Easy |
| 28 | Coin Change | DP (1D) | Medium |
| 29 | Longest Common Subsequence | DP (2D) | Medium |
| 30 | Number of 1 Bits | Bit Manipulation | Easy |

## 🚀 Quick Start

### Visual Studio 2022/2026 (Recommended for Windows)

**The easiest way to work with this project on Windows:**

1. **Open the Solution**
   ```
   Double-click dsa-30days-cpp.sln
   ```

2. **Build and Run**
   - Select your desired project in Solution Explorer (DSA_Learning_GUI or any Day01-Day30)
   - Press `F5` to build and run with debugging
   - Or press `Ctrl+F5` to run without debugging

3. **Features You Get**
   - Full IntelliSense code completion
   - Integrated debugging with breakpoints
   - Build all 30 day solutions + GUI with one click
   - Easy project navigation
   - Professional IDE experience

📖 **For detailed Visual Studio instructions, see [VISUAL_STUDIO_GUIDE.md](VISUAL_STUDIO_GUIDE.md)**

### Windows (GUI) - Alternative Build Method

1. **Prerequisites:**
   - Windows 10 or later
   - Visual Studio 2022 (Community Edition is free)
   - CMake 3.15 or later

2. **Build and Run:**
   ```cmd
   # Clone the repository
   git clone https://github.com/yourusername/dsa-30days-cpp.git
   cd dsa-30days-cpp

   # Build using the provided script
   build.bat

   # Run the GUI application
   build.bat gui
   ```

3. **Using the GUI:**
   - Select a day from the dropdown menu
   - Click "Show Problem" to view the problem statement
   - Click "Show Explanation" to see the detailed approach
   - Click "Run Solution" to execute with test input
   - Click "Run Tests" to verify correctness

### Linux/Mac (CLI)

1. **Prerequisites:**
   - GCC 7+ or Clang with C++17 support
   - CMake 3.15 or later
   - Make (optional)

2. **Build and Run:**
   ```bash
   # Clone the repository
   git clone https://github.com/yourusername/dsa-30days-cpp.git
   cd dsa-30days-cpp

   # Build using the provided script
   ./build.sh

   # Run the interactive launcher
   ./build.sh run
   ```

3. **Using the CLI:**
   - Select a day number (1-30)
   - Choose from menu: Problem, Explanation, Run Solution, or Tests
   - Navigate between days easily

## 🔧 Building from Source

### Using CMake (Recommended - Cross-platform)

```bash
# Create build directory
mkdir build && cd build

# Configure
cmake ..

# Build (uses all available cores)
cmake --build . -j

# Run tests
ctest --output-on-failure

# Install (optional)
cmake --install . --prefix /usr/local
```

### Using CMake with Visual Studio

```cmd
# Create build directory
mkdir build
cd build

# Generate Visual Studio solution
cmake -G "Visual Studio 17 2022" -A x64 ..

# Build
cmake --build . --config Release

# Or open the generated .sln file in Visual Studio
```

### Using Make (Linux only)

```bash
# Build a specific day
make build DAY=01

# Build and test
make test DAY=01

# Build all solutions
make all-build

# Test all solutions
make all-test

# Run interactively
make run DAY=05
```

## 💻 Usage

### Windows GUI Features

The Windows GUI application provides:
- **Day Selection**: Dropdown menu to choose any day
- **Problem Viewer**: Read problem statements in formatted text
- **Explanation Viewer**: Study detailed explanations and approaches
- **Solution Runner**: Execute solutions with test inputs
- **Test Runner**: Automated testing with expected outputs
- **Monospace Font**: Better code readability with Consolas font

### Linux CLI Features

The terminal-based launcher offers:
- **Interactive Menu**: Easy navigation with numbered options
- **File Display**: View markdown files directly in terminal
- **Solution Execution**: Run solutions with test cases
- **Test Automation**: CTest integration for automated testing
- **Day Switching**: Quickly jump between different days

### Running Individual Solutions

```bash
# Linux/Mac
./build/bin/day01 < tests/Day01/input.txt

# Windows
.\build\bin\Release\day01.exe < tests\Day01\input.txt
```

### Running Specific Tests

```bash
# Linux/Mac
cd build && ctest -R Test_Day01 --verbose

# Windows
cd build
ctest -C Release -R Test_Day01 --verbose
```

## 🧪 Testing

### Automated Testing

Each day includes comprehensive test cases:

```bash
# Test all days
cmake --build build --target test

# Test specific day (CMake)
ctest -R Test_Day15

# Test all (Make - Linux only)
make all-test
```

### Manual Testing

```bash
# Compare output manually
./build/bin/day01 < tests/Day01/input.txt > output.txt
diff output.txt tests/Day01/expected.txt
```

### Test Structure
- `tests/DayXX/input.txt` - Input for the problem
- `tests/DayXX/expected.txt` - Expected correct output

## 📖 Understanding the Code

### Extensive Comments

All solution files include:
- **Header Documentation**: Problem description and approach overview
- **Function Documentation**: @brief, @param, @return tags
- **Inline Comments**: Line-by-line explanation of logic
- **Algorithm Walkthrough**: Step-by-step example execution
- **Complexity Analysis**: Time and space complexity breakdown
- **Optimization Notes**: Why certain approaches are chosen

Example from Day01 (Two Sum):
```cpp
// Hash map to store: {number_value -> index_in_array}
// This allows O(1) lookup to check if complement exists
unordered_map<int, int> numMap;

// Iterate through each element in the array
for (int i = 0; i < nums.size(); i++) {
    // Calculate what number we need to reach the target
    // If current number is 2 and target is 9, we need 7
    int complement = target - nums[i];

    // Check if we've already seen the complement
    if (numMap.find(complement) != numMap.end()) {
        return {numMap[complement], i};
    }

    // Store current number for future lookups
    numMap[nums[i]] = i;
}
```

## 🛠️ IDE Support

### Visual Studio 2022/2026 (Native Solution)

**Recommended approach - Native Visual Studio solution:**

1. Double-click `dsa-30days-cpp.sln` in the project root
2. Visual Studio opens with all 31 projects loaded
3. Select your configuration (Debug/Release) and platform (x64)
4. Right-click any project → Set as Startup Project
5. Press F5 to build and run
6. Full debugging, IntelliSense, and IDE integration

**Alternative - CMake folder mode:**

1. Open Visual Studio 2022
2. Select "Open a local folder"
3. Navigate to the `dsa-30days-cpp` folder
4. Visual Studio will automatically detect CMakeLists.txt
5. Select your configuration (Debug/Release)
6. Build and run from IDE

📖 **See [VISUAL_STUDIO_GUIDE.md](VISUAL_STUDIO_GUIDE.md) for complete Visual Studio instructions**

### Visual Studio Code

1. Install extensions:
   - C/C++
   - CMake Tools
   - CMake
2. Open folder in VS Code
3. Configure CMake kit (select compiler)
4. Build using CMake panel

### CLion

1. Open the project folder
2. CLion automatically detects CMake configuration
3. Select build configuration
4. Build and run

## 🎯 Learning Tips

1. **Consistency** - Solve at least one problem per day
2. **Understanding over memorization** - Focus on understanding patterns
3. **Use the GUI/CLI** - Leverage the tools to streamline your workflow
4. **Read Comments** - Study the extensive documentation in each solution
5. **Review regularly** - Revisit problems after a week
6. **Track progress** - Use the testing framework to verify understanding

## 📊 Complexity Reference

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Hash table lookup |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Array traversal |
| O(n log n) | Linearithmic | Merge sort |
| O(n²) | Quadratic | Nested loops |
| O(2ⁿ) | Exponential | Recursive fibonacci |

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Report bugs** - Open an issue if you find errors
2. **Suggest improvements** - Better explanations or optimizations
3. **Add test cases** - More comprehensive testing
4. **Improve GUI/CLI** - Enhance user experience
5. **Fix typos** - Documentation improvements

### Contribution Guidelines

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Follow the existing code style and comment format
4. Test thoroughly on both Windows and Linux
5. Update documentation as needed
6. Commit with clear messages
7. Push to your fork
8. Create a Pull Request

## 🐛 Troubleshooting

### Windows Build Issues

**CMake not found:**
```cmd
# Install CMake from https://cmake.org/download/
# Or use Visual Studio Installer to add CMake
```

**Visual Studio not found:**
```cmd
# Run build.bat from "Developer Command Prompt for VS 2022"
# Or install Visual Studio 2022 Community Edition
```

### Linux Build Issues

**CMake not found:**
```bash
# Ubuntu/Debian
sudo apt-get install cmake build-essential

# Fedora
sudo dnf install cmake gcc-c++

# macOS
brew install cmake
```

**Compiler too old:**
```bash
# Ensure GCC 7+ or Clang with C++17 support
g++ --version
```

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙏 Acknowledgments

- Problems inspired by LeetCode, HackerRank, and other competitive programming platforms
- Community contributions and feedback
- Classic algorithms and data structures literature

## 📞 Contact & Support

- **Issues**: [GitHub Issues](https://github.com/yourusername/dsa-30days-cpp/issues)
- **Discussions**: [GitHub Discussions](https://github.com/yourusername/dsa-30days-cpp/discussions)

## 🌟 Star History

If you find this repository helpful, please consider giving it a star ⭐

---

**Happy Coding! 🚀**

Built with ❤️ for developers learning DSA. Whether you're on Windows using the sleek GUI or Linux with the powerful CLI, we've got you covered!

Remember: The key to mastering DSA is consistent practice and deep understanding. Take your time, use the provided tools, read the extensive comments, and enjoy the learning journey!
