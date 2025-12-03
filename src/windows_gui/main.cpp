// ============================================================================
// main.cpp - Windows GUI Application for DSA 30-Day Challenge
// ============================================================================
// This application provides an interactive GUI for Windows users to:
// - Select which day to learn
// - View problem statements
// - View explanations
// - Run solutions
// - See test results
// ============================================================================

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <commctrl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

// Link required libraries
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// ============================================================================
// Constants and Global Variables
// ============================================================================

// Window dimensions
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

// Layout constants for better UI formatting
const int MARGIN_LEFT = 20;
const int MARGIN_TOP = 20;
const int MARGIN_RIGHT = 20;
const int CONTROL_SPACING = 15;
const int SECTION_SPACING = 25;
const int BUTTON_WIDTH = 220;
const int BUTTON_HEIGHT = 35;
const int COMBO_WIDTH = 250;
const int COMBO_HEIGHT = 25;

// Control IDs
#define IDC_DAY_COMBO 1001
#define IDC_PROBLEM_BTN 1002
#define IDC_EXPLANATION_BTN 1003
#define IDC_RUN_BTN 1004
#define IDC_TEST_BTN 1005
#define IDC_OUTPUT_EDIT 1006
#define IDC_DAY_LIST 1007

// Global variables
HWND g_hWnd = NULL;                    // Main window handle
HWND g_hComboDay = NULL;              // Day selection combo box
HWND g_hOutputEdit = NULL;            // Output text area
HWND g_hListView = NULL;              // Day list view
int g_currentDay = 1;                 // Currently selected day

// ============================================================================
// Helper Functions
// ============================================================================

/**
 * @brief Reads content from a file and returns it as a string
 * @param filename Path to the file to read
 * @return File contents as string, or error message if file doesn't exist
 */
std::wstring ReadFileContent(const std::wstring& filename) {
    std::wifstream file(filename);
    
    if (!file.is_open()) {
        return L"Error: Could not open file: " + filename;
    }

    std::wstringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

/**
 * @brief Converts integer to 2-digit string (e.g., 1 -> "01")
 * @param day Day number (1-30)
 * @return Formatted string with leading zero if needed
 */
std::wstring FormatDayNumber(int day) {
    wchar_t buffer[3];
    swprintf(buffer, 3, L"%02d", day);
    return std::wstring(buffer);
}

/**
 * @brief Gets the path to a specific day's directory
 * @param day Day number (1-30)
 * @return Path to day directory in src folder
 */
std::wstring GetDayPath(int day) {
    return L"src\\Day" + FormatDayNumber(day) + L"\\";
}

/**
 * @brief Displays text in the output edit control
 * @param text Text to display
 */
void DisplayOutput(const std::wstring& text) {
    SetWindowTextW(g_hOutputEdit, text.c_str());
}

/**
 * @brief Shows the problem statement for the selected day
 */
void ShowProblem() {
    std::wstring path = GetDayPath(g_currentDay) + L"problem.md";
    std::wstring content = ReadFileContent(path);
    DisplayOutput(content);
}

/**
 * @brief Shows the explanation for the selected day
 */
void ShowExplanation() {
    std::wstring path = GetDayPath(g_currentDay) + L"explanation.md";
    std::wstring content = ReadFileContent(path);
    DisplayOutput(content);
}

/**
 * @brief Runs the solution for the selected day with test input
 */
void RunSolution() {
    // Build the command to run the solution
    std::wstring dayNum = FormatDayNumber(g_currentDay);
    std::wstring command = L"bin\\day" + dayNum + L".exe < tests\\Day" +
                          dayNum + L"\\input.txt";

    // Execute the command and capture output
    std::wstring output =
        L"═══════════════════════════════════════════════════════════════════════\n"
        L"  ▶️  RUNNING SOLUTION - Day " + dayNum + L"\n"
        L"═══════════════════════════════════════════════════════════════════════\n\n"
        L"📁 Executable: bin\\day" + dayNum + L".exe\n"
        L"📄 Input File: tests\\Day" + dayNum + L"\\input.txt\n\n"
        L"───────────────────────────────────────────────────────────────────────\n\n"
        L"ℹ️  NOTE:\n\n"
        L"  To see the actual execution output, you need to:\n\n"
        L"  1️⃣  Build the project first:\n"
        L"      cmake --build build\n\n"
        L"  2️⃣  Run from command line:\n"
        L"      " + command + L"\n\n"
        L"───────────────────────────────────────────────────────────────────────\n\n"
        L"💡 TIP: The solution will read input from the test file and display\n"
        L"        the output in the console.\n\n"
        L"═══════════════════════════════════════════════════════════════════════\n";

    DisplayOutput(output);
}

/**
 * @brief Runs tests for the selected day
 */
void RunTests() {
    std::wstring dayNum = FormatDayNumber(g_currentDay);

    std::wstring output =
        L"═══════════════════════════════════════════════════════════════════════\n"
        L"  ✓  RUNNING TESTS - Day " + dayNum + L"\n"
        L"═══════════════════════════════════════════════════════════════════════\n\n"
        L"📂 Test Files:\n\n"
        L"  📄 Input:    tests\\Day" + dayNum + L"\\input.txt\n"
        L"  📄 Expected: tests\\Day" + dayNum + L"\\expected.txt\n\n"
        L"───────────────────────────────────────────────────────────────────────\n\n"
        L"🔧 AUTOMATED TESTING:\n\n"
        L"  Run all tests using CMake/CTest:\n\n"
        L"    cmake --build build --target test\n\n"
        L"  Or run a specific day's test:\n\n"
        L"    cd build\n"
        L"    ctest -R Day" + dayNum + L" -V\n\n"
        L"───────────────────────────────────────────────────────────────────────\n\n"
        L"📊 TEST VALIDATION:\n\n"
        L"  The test compares the actual output of your solution with the\n"
        L"  expected output file to verify correctness.\n\n"
        L"═══════════════════════════════════════════════════════════════════════\n";

    DisplayOutput(output);
}

// ============================================================================
// Window Procedure - Handles all window messages
// ============================================================================

/**
 * @brief Main window procedure that processes messages
 * @param hwnd Window handle
 * @param uMsg Message type
 * @param wParam Message parameter (varies by message type)
 * @param lParam Message parameter (varies by message type)
 * @return Result of message processing
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        // ====================================================================
        // Window Creation
        // ====================================================================
        case WM_CREATE: {
            // Initialize common controls
            INITCOMMONCONTROLSEX icex;
            icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
            icex.dwICC = ICC_LISTVIEW_CLASSES | ICC_TAB_CLASSES;
            InitCommonControlsEx(&icex);

            // Calculate layout positions
            int yPos = MARGIN_TOP;

            // ================================================================
            // Title Section
            // ================================================================
            HWND hTitle = CreateWindowW(L"STATIC",
                L"30-Day DSA Challenge - Interactive Learning Tool",
                WS_VISIBLE | WS_CHILD | SS_CENTER,
                MARGIN_LEFT, yPos, WINDOW_WIDTH - MARGIN_LEFT - MARGIN_RIGHT, 40,
                hwnd, NULL, NULL, NULL);

            // Set larger font for title
            HFONT hTitleFont = CreateFontW(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
            SendMessageW(hTitle, WM_SETFONT, (WPARAM)hTitleFont, TRUE);

            yPos += 40 + SECTION_SPACING;

            // ================================================================
            // Day Selection Section
            // ================================================================
            // Day selection label
            HWND hDayLabel = CreateWindowW(L"STATIC", L"Select Day:",
                WS_VISIBLE | WS_CHILD,
                MARGIN_LEFT, yPos, 150, 20,
                hwnd, NULL, NULL, NULL);

            // Set font for label
            HFONT hLabelFont = CreateFontW(14, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
            SendMessageW(hDayLabel, WM_SETFONT, (WPARAM)hLabelFont, TRUE);

            yPos += 25;

            // Create day selection combo box with better size
            g_hComboDay = CreateWindowW(L"COMBOBOX", NULL,
                WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
                MARGIN_LEFT, yPos, COMBO_WIDTH, 400,
                hwnd, (HMENU)IDC_DAY_COMBO, NULL, NULL);

            // Set font for combo box
            HFONT hComboFont = CreateFontW(14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
            SendMessageW(g_hComboDay, WM_SETFONT, (WPARAM)hComboFont, TRUE);

            // Populate combo box with days
            for (int i = 1; i <= 30; i++) {
                wchar_t buffer[50];
                swprintf(buffer, 50, L"Day %02d", i);
                SendMessageW(g_hComboDay, CB_ADDSTRING, 0, (LPARAM)buffer);
            }
            SendMessageW(g_hComboDay, CB_SETCURSEL, 0, 0);  // Select Day 01

            yPos += COMBO_HEIGHT + SECTION_SPACING;

            // ================================================================
            // Action Buttons Section
            // ================================================================
            // Actions label
            HWND hActionsLabel = CreateWindowW(L"STATIC", L"Actions:",
                WS_VISIBLE | WS_CHILD,
                MARGIN_LEFT, yPos, 150, 20,
                hwnd, NULL, NULL, NULL);
            SendMessageW(hActionsLabel, WM_SETFONT, (WPARAM)hLabelFont, TRUE);

            yPos += 25;

            // First row of buttons
            int xPos = MARGIN_LEFT;

            HWND hProblemBtn = CreateWindowW(L"BUTTON", L"📄 Show Problem",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                xPos, yPos, BUTTON_WIDTH, BUTTON_HEIGHT,
                hwnd, (HMENU)IDC_PROBLEM_BTN, NULL, NULL);
            SendMessageW(hProblemBtn, WM_SETFONT, (WPARAM)hComboFont, TRUE);

            xPos += BUTTON_WIDTH + CONTROL_SPACING;

            HWND hExplanationBtn = CreateWindowW(L"BUTTON", L"📖 Show Explanation",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                xPos, yPos, BUTTON_WIDTH, BUTTON_HEIGHT,
                hwnd, (HMENU)IDC_EXPLANATION_BTN, NULL, NULL);
            SendMessageW(hExplanationBtn, WM_SETFONT, (WPARAM)hComboFont, TRUE);

            xPos += BUTTON_WIDTH + CONTROL_SPACING;

            HWND hRunBtn = CreateWindowW(L"BUTTON", L"▶️ Run Solution",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                xPos, yPos, BUTTON_WIDTH, BUTTON_HEIGHT,
                hwnd, (HMENU)IDC_RUN_BTN, NULL, NULL);
            SendMessageW(hRunBtn, WM_SETFONT, (WPARAM)hComboFont, TRUE);

            // Second row of buttons
            yPos += BUTTON_HEIGHT + CONTROL_SPACING;
            xPos = MARGIN_LEFT;

            HWND hTestBtn = CreateWindowW(L"BUTTON", L"✓ Run Tests",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                xPos, yPos, BUTTON_WIDTH, BUTTON_HEIGHT,
                hwnd, (HMENU)IDC_TEST_BTN, NULL, NULL);
            SendMessageW(hTestBtn, WM_SETFONT, (WPARAM)hComboFont, TRUE);

            yPos += BUTTON_HEIGHT + SECTION_SPACING;

            // ================================================================
            // Output Section
            // ================================================================
            // Output label
            HWND hOutputLabel = CreateWindowW(L"STATIC", L"Output:",
                WS_VISIBLE | WS_CHILD,
                MARGIN_LEFT, yPos, 150, 20,
                hwnd, NULL, NULL, NULL);
            SendMessageW(hOutputLabel, WM_SETFONT, (WPARAM)hLabelFont, TRUE);

            yPos += 25;

            // Create output text area with scrollbars
            int outputHeight = WINDOW_HEIGHT - yPos - MARGIN_TOP - 40;
            g_hOutputEdit = CreateWindowW(L"EDIT", L"",
                WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | WS_HSCROLL |
                ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_READONLY,
                MARGIN_LEFT, yPos, WINDOW_WIDTH - MARGIN_LEFT - MARGIN_RIGHT, outputHeight,
                hwnd, (HMENU)IDC_OUTPUT_EDIT, NULL, NULL);

            // Set a monospace font for better code display
            HFONT hOutputFont = CreateFontW(14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, L"Consolas");
            SendMessageW(g_hOutputEdit, WM_SETFONT, (WPARAM)hOutputFont, TRUE);

            // Display welcome message with better formatting
            DisplayOutput(
                L"═══════════════════════════════════════════════════════════════════════\n"
                L"  Welcome to the 30-Day DSA Challenge!\n"
                L"═══════════════════════════════════════════════════════════════════════\n\n"
                L"📚 HOW TO USE:\n\n"
                L"  1️⃣  Select a day from the 'Select Day' dropdown\n"
                L"  2️⃣  Click '📄 Show Problem' to view the problem statement\n"
                L"  3️⃣  Click '📖 Show Explanation' to see the detailed solution\n"
                L"  4️⃣  Click '▶️ Run Solution' to execute the solution code\n"
                L"  5️⃣  Click '✓ Run Tests' to run automated tests\n\n"
                L"───────────────────────────────────────────────────────────────────────\n\n"
                L"⚙️  BUILD INSTRUCTIONS:\n\n"
                L"  Make sure you've built the project using CMake before running solutions:\n\n"
                L"    mkdir build\n"
                L"    cd build\n"
                L"    cmake ..\n"
                L"    cmake --build .\n\n"
                L"───────────────────────────────────────────────────────────────────────\n\n"
                L"💡 TIP: Start with Day 01 and work your way through each challenge!\n\n"
                L"═══════════════════════════════════════════════════════════════════════\n"
            );

            return 0;
        }

        // ====================================================================
        // Command Processing (Button Clicks, Menu Selections)
        // ====================================================================
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                // Day selection changed
                case IDC_DAY_COMBO:
                    if (HIWORD(wParam) == CBN_SELCHANGE) {
                        int sel = SendMessageW(g_hComboDay, CB_GETCURSEL, 0, 0);
                        g_currentDay = sel + 1;  // Days are 1-indexed
                    }
                    break;

                // Show Problem button clicked
                case IDC_PROBLEM_BTN:
                    ShowProblem();
                    break;

                // Show Explanation button clicked
                case IDC_EXPLANATION_BTN:
                    ShowExplanation();
                    break;

                // Run Solution button clicked
                case IDC_RUN_BTN:
                    RunSolution();
                    break;

                // Run Tests button clicked
                case IDC_TEST_BTN:
                    RunTests();
                    break;
            }
            return 0;
        }

        // ====================================================================
        // Window Destruction
        // ====================================================================
        case WM_DESTROY:
            PostQuitMessage(0);  // Exit the application
            return 0;

        // ====================================================================
        // Paint Event (for custom drawing if needed)
        // ====================================================================
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Custom painting code would go here
            EndPaint(hwnd, &ps);
            return 0;
        }
    }

    // Default message processing
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

// ============================================================================
// WinMain - Application Entry Point
// ============================================================================

/**
 * @brief Main entry point for Windows GUI application
 * @param hInstance Handle to current instance
 * @param hPrevInstance Handle to previous instance (always NULL in Win32)
 * @param lpCmdLine Command line arguments
 * @param nCmdShow How to show the window (minimized, maximized, etc.)
 * @return Exit code
 */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
    // Unused parameters
    (void)hPrevInstance;
    (void)lpCmdLine;

    // ========================================================================
    // Register Window Class
    // ========================================================================
    const wchar_t CLASS_NAME[] = L"DSA30DayWindow";

    WNDCLASSW wc = { };
    wc.lpfnWndProc = WindowProc;           // Window procedure
    wc.hInstance = hInstance;               // Instance handle
    wc.lpszClassName = CLASS_NAME;          // Class name
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // Background color
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);       // Cursor
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);     // Icon

    if (!RegisterClassW(&wc)) {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // ========================================================================
    // Create Window
    // ========================================================================
    g_hWnd = CreateWindowExW(
        0,                                  // Extended window style
        CLASS_NAME,                         // Window class name
        L"DSA 30-Day Challenge",           // Window title
        WS_OVERLAPPEDWINDOW,               // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,     // Position (x, y)
        WINDOW_WIDTH, WINDOW_HEIGHT,       // Size (width, height)
        NULL,                              // Parent window
        NULL,                              // Menu
        hInstance,                         // Instance handle
        NULL                               // Additional application data
    );

    if (g_hWnd == NULL) {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Display the window
    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    // ========================================================================
    // Message Loop
    // ========================================================================
    MSG msg = { };

    // Process messages until WM_QUIT is received
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);  // Translate keyboard messages
        DispatchMessageW(&msg);  // Send message to window procedure
    }

    // Return exit code
    return (int)msg.wParam;
}
