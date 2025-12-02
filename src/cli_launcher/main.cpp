// ============================================================================
// main.cpp - Linux CLI Launcher for DSA 30-Day Challenge
// ============================================================================
// This provides an interactive command-line interface for Linux users to:
// - Select which day to learn
// - View problem statements
// - View explanations
// - Run solutions
// ============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>

/**
 * @brief Clears the terminal screen (cross-platform)
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Formats day number with leading zero
 * @param day Day number (1-30)
 * @return Formatted string (e.g., "01", "15")
 */
std::string formatDayNumber(int day) {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day;
    return oss.str();
}

/**
 * @brief Reads and displays content from a file
 * @param filename Path to the file
 * @return true if successful, false otherwise
 */
bool displayFile(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    
    file.close();
    return true;
}

/**
 * @brief Displays the main menu and gets user choice
 * @return User's menu choice
 */
int displayMenu() {
    std::cout << "\n====================================\n";
    std::cout << "  30-Day DSA Challenge Menu\n";
    std::cout << "====================================\n";
    std::cout << "1. Show Problem\n";
    std::cout << "2. Show Explanation\n";
    std::cout << "3. Run Solution\n";
    std::cout << "4. Run Tests\n";
    std::cout << "5. Change Day\n";
    std::cout << "0. Exit\n";
    std::cout << "====================================\n";
    std::cout << "Enter your choice: ";
    
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline from buffer
    
    return choice;
}

/**
 * @brief Displays available days and gets user selection
 * @return Selected day number
 */
int selectDay() {
    std::cout << "\n====================================\n";
    std::cout << "  Select Day (1-30)\n";
    std::cout << "====================================\n";
    
    // Display days in a grid
    for (int i = 1; i <= 30; i++) {
        std::cout << std::setw(3) << i;
        if (i % 10 == 0) std::cout << std::endl;
    }
    
    std::cout << "\n====================================\n";
    std::cout << "Enter day number: ";
    
    int day;
    std::cin >> day;
    std::cin.ignore();
    
    // Validate input
    if (day < 1 || day > 30) {
        std::cout << "Invalid day! Using Day 1.\n";
        return 1;
    }
    
    return day;
}

/**
 * @brief Main application entry point
 */
int main() {
    int currentDay = 1;
    bool running = true;
    
    clearScreen();
    std::cout << "====================================\n";
    std::cout << "  Welcome to 30-Day DSA Challenge!\n";
    std::cout << "====================================\n";
    
    currentDay = selectDay();
    
    while (running) {
        clearScreen();
        
        std::string dayStr = formatDayNumber(currentDay);
        std::cout << "\n>>> Currently on Day " << dayStr << " <<<\n";
        
        int choice = displayMenu();
        
        switch (choice) {
            case 1: { // Show Problem
                clearScreen();
                std::cout << "\n=== Problem for Day " << dayStr << " ===\n\n";
                std::string filename = "src/Day" + dayStr + "/problem.md";
                displayFile(filename);

                std::cout << "\n\nPress Enter to continue...";
                std::cin.get();
                break;
            }

            case 2: { // Show Explanation
                clearScreen();
                std::cout << "\n=== Explanation for Day " << dayStr << " ===\n\n";
                std::string filename = "src/Day" + dayStr + "/explanation.md";
                displayFile(filename);

                std::cout << "\n\nPress Enter to continue...";
                std::cin.get();
                break;
            }
            
            case 3: { // Run Solution
                clearScreen();
                std::cout << "\n=== Running Solution for Day " << dayStr << " ===\n\n";
                
                std::string command = "./build/bin/day" + dayStr + 
                                    " < tests/Day" + dayStr + "/input.txt";
                
                std::cout << "Executing: " << command << "\n\n";
                int result = system(command.c_str());
                
                if (result != 0) {
                    std::cout << "\nNote: Make sure you've built the project first!\n";
                    std::cout << "Build with: mkdir build && cd build && cmake .. && cmake --build .\n";
                }
                
                std::cout << "\n\nPress Enter to continue...";
                std::cin.get();
                break;
            }
            
            case 4: { // Run Tests
                clearScreen();
                std::cout << "\n=== Running Tests for Day " << dayStr << " ===\n\n";
                
                std::string command = "cd build && ctest -R Test_Day" + dayStr + " --verbose";
                
                std::cout << "Executing: " << command << "\n\n";
                system(command.c_str());
                
                std::cout << "\n\nPress Enter to continue...";
                std::cin.get();
                break;
            }
            
            case 5: { // Change Day
                currentDay = selectDay();
                break;
            }
            
            case 0: { // Exit
                running = false;
                std::cout << "\nThank you for using the DSA 30-Day Challenge!\n";
                std::cout << "Keep practicing and happy coding! 🚀\n\n";
                break;
            }
            
            default: {
                std::cout << "\nInvalid choice! Please try again.\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
                break;
            }
        }
    }
    
    return 0;
}
