# Visual Studio Setup Guide

This guide will help you open and work with the DSA 30-Day Challenge project in Visual Studio 2022/2026.

## Prerequisites

- **Visual Studio 2022 or later** (Community, Professional, or Enterprise)
- **C++ Desktop Development workload** installed
- **Windows 10 SDK** (automatically installed with C++ workload)

## Quick Start

### Opening the Project

1. **Locate the Solution File**
   - Navigate to the project root directory
   - Find `dsa-30days-cpp.sln`

2. **Open in Visual Studio**
   - Double-click `dsa-30days-cpp.sln`, or
   - Open Visual Studio → File → Open → Project/Solution → Select `dsa-30days-cpp.sln`

3. **Wait for Solution to Load**
   - Visual Studio will load all 31 projects (1 GUI + 30 Day solutions)
   - You'll see all projects in the Solution Explorer

## Project Structure

The solution contains:

```
dsa-30days-cpp.sln                    # Main solution file
├── DSA_Learning_GUI                  # Windows GUI Application
│   └── src/windows_gui/
│       ├── main.cpp                  # GUI source code
│       └── resource.rc               # Windows resources
│
└── Day01 - Day30                     # Daily solution projects
    └── src/DayXX/
        └── solution.cpp              # Solution implementation
```

## Building the Project

### Build All Projects

1. **Select Build Configuration**
   - Click the configuration dropdown (usually shows "Debug")
   - Choose `Debug` or `Release`
   - Choose platform: `x64` (recommended)

2. **Build the Entire Solution**
   - Menu: Build → Build Solution, or
   - Press `Ctrl+Shift+B`
   - All projects will compile
   - Output will be in `bin/Debug/` or `bin/Release/`

### Build Individual Projects

1. **In Solution Explorer**
   - Right-click the project you want to build (e.g., "Day01" or "DSA_Learning_GUI")
   - Select "Build"

2. **Set as Startup Project**
   - Right-click the project
   - Select "Set as Startup Project"
   - The project name will appear bold
   - Press `F5` to run or `Ctrl+F5` to run without debugging

## Running Projects

### Running the GUI Application

1. **Set DSA_Learning_GUI as Startup Project**
   - Right-click "DSA_Learning_GUI" in Solution Explorer
   - Select "Set as Startup Project"

2. **Run the Application**
   - Press `F5` (with debugging) or `Ctrl+F5` (without debugging)
   - The GUI window will open
   - Use the interface to explore daily challenges

### Running Individual Day Solutions

1. **Set the Day Project as Startup**
   - Right-click "Day01" (or any other day) in Solution Explorer
   - Select "Set as Startup Project"

2. **Run with Input**
   - To provide test input, you have two options:

   **Option A: Using Command Line Arguments**
   - Right-click the project → Properties
   - Configuration Properties → Debugging
   - Set "Command Arguments" to: `< ../../tests/Day01/input.txt`
   - Click OK
   - Press `F5` to run

   **Option B: Redirect Input in Code**
   - Temporarily add to the beginning of main():
   ```cpp
   freopen("../../tests/Day01/input.txt", "r", stdin);
   ```
   - Press `F5` to run
   - Remove after testing

   **Option C: Manual Input**
   - Just press `F5` and type input manually in the console window

3. **View Output**
   - Output will appear in the console window
   - To save output, redirect in project properties:
     - Debugging → Command Arguments: `< input.txt > output.txt`

## Configuration Details

### Debug vs Release

- **Debug Configuration**
  - Includes debug symbols
  - No optimizations
  - Easier to debug with breakpoints
  - Slower execution
  - Use during development

- **Release Configuration**
  - Optimized for speed (-O2)
  - Smaller executable size
  - No debug information
  - Use for final testing and performance

### Build Output Directories

All executables are built to:
- **Debug builds**: `bin/Debug/`
- **Release builds**: `bin/Release/`

Intermediate files (object files) go to:
- `obj/Debug/ProjectName/`
- `obj/Release/ProjectName/`

## Debugging

### Setting Breakpoints

1. Open a source file (e.g., `src/Day01/solution.cpp`)
2. Click in the left margin next to the line number
3. A red dot appears (breakpoint)
4. Press `F5` to start debugging
5. Execution will pause at breakpoints

### Debug Controls

- **F5** - Start debugging or continue
- **F10** - Step over (execute current line)
- **F11** - Step into (enter function)
- **Shift+F11** - Step out (exit function)
- **Ctrl+Shift+F5** - Restart debugging
- **Shift+F5** - Stop debugging

### Watch Variables

- Hover over variables to see values
- Add variables to Watch window: Debug → Windows → Watch
- View locals: Debug → Windows → Locals
- View call stack: Debug → Windows → Call Stack

## Common Tasks

### Adding a New Day Solution

If you create a new day (Day31, for example):

1. Create the directory: `src/Day31/`
2. Add `solution.cpp`
3. Run the Python script to generate project files:
   ```cmd
   python generate_vcxproj.py
   ```
4. Reload the solution in Visual Studio

### Changing C++ Standard

To use a different C++ standard (C++20, C++23):

1. Right-click project → Properties
2. C/C++ → Language
3. C++ Language Standard → Select version
4. Apply to all projects if needed

### Modifying Compiler Flags

1. Right-click project → Properties
2. C/C++ → Command Line
3. Add additional options in "Additional Options"

Example flags:
- `/std:c++20` - Use C++20
- `/W4` - Warning level 4 (already set)
- `/WX` - Treat warnings as errors

## Troubleshooting

### "Cannot open include file"

**Problem**: Header files not found

**Solution**:
1. Right-click project → Properties
2. C/C++ → General → Additional Include Directories
3. Add: `$(SolutionDir);$(SolutionDir)src`

### "LNK1104: cannot open file"

**Problem**: Linker cannot find libraries

**Solution**:
1. Check that Windows SDK is installed
2. Verify platform is x64 (not Win32)
3. Clean and rebuild: Build → Clean Solution, then Build → Build Solution

### "Access Denied" when building

**Problem**: File is locked or in use

**Solution**:
1. Close any running instances of your program
2. Close Visual Studio
3. Delete `bin/` and `obj/` folders
4. Reopen Visual Studio and rebuild

### GUI Application Doesn't Start

**Problem**: Window doesn't appear

**Solution**:
1. Check that DSA_Learning_GUI is set as startup project
2. Verify it's built as a Windows Application (not Console)
3. Check project properties → Linker → System → SubSystem = "Windows (/SUBSYSTEM:WINDOWS)"

### Build Fails with "v143 not found"

**Problem**: Platform toolset version mismatch

**Solution**:
1. Right-click project → Properties
2. Configuration Properties → General
3. Platform Toolset → Select your installed version (e.g., v143 for VS2022)
4. Apply to all configurations

## Best Practices

### Working with Multiple Solutions

- Keep only one day project as startup project at a time
- Use "Batch Build" to build specific projects: Build → Batch Build
- Unload unused projects to speed up solution loading: Right-click project → Unload Project

### Code Navigation

- **Go to Definition**: `F12` or right-click → Go to Definition
- **Find All References**: `Shift+F12`
- **Navigate Back**: `Ctrl+-`
- **Navigate Forward**: `Ctrl+Shift+-`

### Performance Tips

- Use Release configuration for performance testing
- Profile with Visual Studio Profiler: Debug → Performance Profiler
- Use "Build Only" instead of "Rebuild" when possible

## Additional Resources

- [Visual Studio C++ Documentation](https://docs.microsoft.com/en-us/cpp/)
- [Debugging in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/debugger/)
- [MSBuild Reference](https://docs.microsoft.com/en-us/visualstudio/msbuild/)

## Support

If you encounter issues:

1. Check this guide's Troubleshooting section
2. Verify all prerequisites are installed
3. Try cleaning and rebuilding the solution
4. Check that you're using Visual Studio 2022 or later

---

**Happy Coding with Visual Studio!** 🚀

You now have full IDE support with IntelliSense, debugging, and all the powerful features of Visual Studio at your fingertips!
