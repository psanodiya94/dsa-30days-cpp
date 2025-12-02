# Quick Setup Guide

This guide will help you get started in under 5 minutes!

## For Windows Users

### Option 1: One-Click Build (Recommended)
1. Double-click `build.bat`
2. Wait for build to complete
3. Run the GUI: `build\bin\Release\DSA_Learning.exe`

### Option 2: Visual Studio
1. Open Visual Studio 2022
2. File → Open → Folder → Select `dsa-30days-cpp`
3. Wait for CMake to configure (bottom status bar)
4. Select build configuration (top toolbar): `x64-Release`
5. Build → Build All
6. Run `DSA_Learning_GUI` from the dropdown

### Option 3: Command Line
```cmd
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build . --config Release
cd ..
build\bin\Release\DSA_Learning.exe
```

## For Linux/Mac Users

### Option 1: One-Command Build
```bash
./build.sh run
```

### Option 2: Manual Build
```bash
mkdir build && cd build
cmake .. && cmake --build . -j
cd .. && ./build/bin/dsa
```

### Option 3: Using Make
```bash
make all-build
./build/bin/dsa
```

## First Steps After Building

### Windows GUI Users
1. Select "Day 01" from dropdown
2. Click "Show Problem" to read the challenge
3. Click "Show Explanation" to understand the approach
4. Click "Run Solution" to see it in action

### Linux CLI Users
1. The launcher will start automatically
2. Select day number (1-30)
3. Choose option from menu:
   - 1: Show Problem
   - 2: Show Explanation
   - 3: Run Solution
   - 4: Run Tests

## Verifying Your Setup

### Run a Test
```bash
# Linux/Mac
./build/bin/day01 < tests/Day01/input.txt

# Windows
.\build\bin\Release\day01.exe < tests\Day01\input.txt
```

Expected output: `0 1`

### Run All Tests
```bash
# Linux/Mac
cd build && ctest

# Windows
cd build
ctest -C Release
```

## Common Issues

### "CMake not found"
- **Windows**: Install from https://cmake.org/download/
- **Linux**: `sudo apt-get install cmake` (Ubuntu/Debian)
- **Mac**: `brew install cmake`

### "No compiler found"
- **Windows**: Install Visual Studio 2022 Community (free)
- **Linux**: `sudo apt-get install build-essential`
- **Mac**: `xcode-select --install`

### "Permission denied" (Linux/Mac)
```bash
chmod +x build.sh
```

### GUI doesn't show markdown properly
- Ensure you're running from the project root directory
- Check that src/Day folders exist and contain .md files

## Need Help?

1. Check the main [README.md](README.md) for detailed instructions
2. Open an issue on GitHub
3. Make sure you have all prerequisites installed

## Quick Reference

### Build Commands
| Platform | Command | Description |
|----------|---------|-------------|
| Windows | `build.bat` | Build everything |
| Windows | `build.bat gui` | Build and run GUI |
| Windows | `build.bat test` | Build and run tests |
| Linux/Mac | `./build.sh` | Build everything |
| Linux/Mac | `./build.sh run` | Build and run launcher |
| Linux/Mac | `./build.sh test` | Build and run tests |

### Directory Structure
```
build/
  bin/           # All executables here
    day01        # Individual day solutions
    day02        # (Linux: no extension)
    ...          # (Windows: .exe extension)
    dsa          # CLI launcher (Linux)
    DSA_Learning # GUI app (Windows)
```

Happy learning! 🚀
