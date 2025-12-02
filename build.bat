@echo off
REM ============================================================================
REM build.bat - Windows Build Script
REM ============================================================================
REM This script automates the build process on Windows
REM Usage: build.bat [clean] [test] [gui]
REM ============================================================================

setlocal enabledelayedexpansion

echo =====================================
echo   DSA 30-Day Challenge - Build
echo =====================================
echo.

REM Check if CMake is installed
where cmake >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Error: CMake is not installed!
    echo Please install CMake from https://cmake.org/download/
    echo Or use Visual Studio Installer to add CMake
    pause
    exit /b 1
)

REM Check if Visual Studio is available
where cl >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Warning: Visual Studio compiler not found in PATH
    echo Attempting to find Visual Studio...

    REM Try to find VS 2022
    if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" (
        call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
    ) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat" (
        call "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat"
    ) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat" (
        call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat"
    ) else (
        echo Error: Visual Studio 2022 not found
        echo Please install Visual Studio 2022 or run this from VS Developer Command Prompt
        pause
        exit /b 1
    )
)

REM Parse command line arguments
set CLEAN_BUILD=0
set RUN_TESTS=0
set RUN_GUI=0
set BUILD_TYPE=Release

:parse_args
if "%1"=="" goto done_parsing
if /i "%1"=="clean" set CLEAN_BUILD=1
if /i "%1"=="test" set RUN_TESTS=1
if /i "%1"=="gui" set RUN_GUI=1
if /i "%1"=="debug" set BUILD_TYPE=Debug
shift
goto parse_args
:done_parsing

REM Clean build if requested
if %CLEAN_BUILD%==1 (
    echo Cleaning build directory...
    if exist build rmdir /s /q build
)

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
echo Configuring with CMake...
cmake -G "Visual Studio 17 2022" -A x64 ..
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Error: CMake configuration failed!
    echo Trying with different generator...
    cmake -G "NMake Makefiles" ..
    if %ERRORLEVEL% NEQ 0 (
        echo Configuration failed! Please check your CMake installation.
        cd ..
        pause
        exit /b 1
    )
)

REM Build
echo.
echo Building project...
cmake --build . --config %BUILD_TYPE%
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Build failed!
    cd ..
    pause
    exit /b 1
)

echo.
echo =====================================
echo   Build Completed Successfully!
echo =====================================
echo.

REM Run tests if requested
if %RUN_TESTS%==1 (
    echo Running tests...
    ctest -C %BUILD_TYPE% --output-on-failure
    echo.
)

REM Run GUI if requested
if %RUN_GUI%==1 (
    echo Starting GUI application...
    if exist "bin\%BUILD_TYPE%\DSA_Learning.exe" (
        start "" "bin\%BUILD_TYPE%\DSA_Learning.exe"
    ) else if exist "bin\DSA_Learning.exe" (
        start "" "bin\DSA_Learning.exe"
    ) else (
        echo GUI executable not found!
    )
) else (
    echo Executables are in: build\bin\%BUILD_TYPE%\
    echo.
    echo To run the GUI application:
    echo   build\bin\%BUILD_TYPE%\DSA_Learning.exe
    echo.
    echo To run a specific day:
    echo   build\bin\%BUILD_TYPE%\day01.exe ^< tests\Day01\input.txt
    echo.
    echo To run tests:
    echo   build.bat test
    echo.
    echo To run GUI directly:
    echo   build.bat gui
    echo.
)

cd ..
pause
