# 🚀 30-Day DSA Challenge in C++

A comprehensive 30-day Data Structures and Algorithms learning journey with C++17. Master essential DSA concepts through curated problems with detailed explanations, optimized solutions, and test cases.

## 📚 Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Topics Covered](#topics-covered)
- [Daily Curriculum](#daily-curriculum)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)

## 🎯 Overview

This repository contains a structured 30-day learning path covering fundamental to advanced data structures and algorithms. Each day includes:

- **Problem Statement** (`problem.md`) - Clear problem description with examples and constraints
- **Detailed Explanation** (`explanation.md`) - Approach, intuition, complexity analysis, and walkthroughs
- **Optimized Solution** (`solution.cpp`) - Clean, well-commented C++17 implementation
- **Test Cases** (`tests/DayXX/`) - Sample inputs and expected outputs

## 📁 Project Structure

```
dsa-30days-cpp/
│
├── Day01/
│   ├── problem.md          # Problem statement
│   ├── explanation.md      # Detailed explanation
│   └── solution.cpp        # C++ solution
│
├── Day02/
│   ├── problem.md
│   ├── explanation.md
│   └── solution.cpp
│
├── ... (Day03 - Day30)
│
├── tests/
│   ├── Day01/
│   │   ├── input.txt       # Test input
│   │   └── expected.txt    # Expected output
│   ├── Day02/
│   └── ... (Day03 - Day30)
│
├── Makefile                # Build and test automation
└── README.md              # This file
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

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++17 support (g++ 7+ recommended)
- Make (optional, for using Makefile)
- Git (for cloning the repository)

### Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/dsa-30days-cpp.git
cd dsa-30days-cpp
```

## 💻 Usage

### Using Makefile (Recommended)

```bash
# Show available commands
make help

# Build a specific day's solution
make build DAY=01

# Build and test a specific day
make test DAY=01

# Run a specific day interactively
make run DAY=05

# Build all solutions
make all-build

# Test all solutions
make all-test

# View problem statement
make problem DAY=01

# View explanation
make explain DAY=01

# Clean build artifacts
make clean
```

### Manual Compilation

```bash
# Compile a specific day
g++ -std=c++17 -Wall -Wextra -O2 Day01/solution.cpp -o day01

# Run with test input
./day01 < tests/Day01/input.txt

# Run interactively
./day01
```

## 🧪 Testing

Each day includes test cases in the `tests/DayXX/` directory.

### Test Structure
- `input.txt` - Sample input following the problem format
- `expected.txt` - Expected output for the given input

### Running Tests

```bash
# Test a specific day
make test DAY=01

# Test all days
make all-test
```

### Example Test Output
```
Testing Day01...
✓ Test passed for Day01!

Testing Day02...
✓ Test passed for Day02!

...

Results: 30 passed, 0 failed
```

## 📖 How to Use This Repository

### For Beginners

1. **Start with Day 01** and progress sequentially
2. **Read the problem** (`problem.md`) carefully
3. **Try solving it yourself** before looking at the solution
4. **Read the explanation** (`explanation.md`) to understand different approaches
5. **Study the solution** (`solution.cpp`) and understand the implementation
6. **Test your understanding** by running the test cases
7. **Practice variations** of the problem

### For Intermediate/Advanced Learners

1. **Challenge yourself** - Set a timer and solve under time pressure
2. **Optimize solutions** - Try to improve time/space complexity
3. **Explore alternatives** - Implement different approaches mentioned in explanations
4. **Learn patterns** - Identify common patterns across similar problems
5. **Practice interviews** - Use problems for mock interview practice

## 🎯 Learning Tips

1. **Consistency** - Solve at least one problem per day
2. **Understanding over memorization** - Focus on understanding patterns
3. **Time yourself** - Practice under interview-like conditions
4. **Code by hand** - Try solving without IDE assistance
5. **Review regularly** - Revisit problems after a week
6. **Join communities** - Discuss solutions with others
7. **Track progress** - Maintain a log of problems solved

## 🔧 Customization

### Adding Your Own Solutions

You can add alternative solutions or optimizations:

```cpp
// In DayXX/solution.cpp
class Solution {
public:
    // Original solution
    int originalApproach() { /* ... */ }

    // Your optimized solution
    int optimizedApproach() { /* ... */ }
};
```

### Adding More Test Cases

Create additional test files:

```bash
# Create new test
echo "your input" > tests/Day01/input2.txt
echo "expected output" > tests/Day01/expected2.txt
```

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
4. **Fix typos** - Documentation improvements
5. **Share resources** - Additional learning materials

### Contribution Guidelines

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Make your changes
4. Test thoroughly
5. Commit with clear messages
6. Push to your fork
7. Create a Pull Request

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

Remember: The key to mastering DSA is consistent practice and deep understanding, not just solving problems. Take your time, understand each concept thoroughly, and enjoy the learning journey!
