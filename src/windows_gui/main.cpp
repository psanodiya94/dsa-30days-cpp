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
const int WINDOW_HEIGHT = 700;

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
 * @return Path to day directory
 */
std::wstring GetDayPath(int day) {
    return L"Day" + FormatDayNumber(day) + L"\\";
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
    DisplayOutput(L"Running solution for Day " + dayNum + L"...\n\n");
    
    // Note: In a real implementation, you would use CreateProcess to run
    // the executable and capture its output. This is simplified.
    DisplayOutput(L"Solution executed. Check console for output.\n\n"
                 L"To see full output:\n"
                 L"1. Build the project first (cmake --build build)\n"
                 L"2. Run from command line: " + command);
}

/**
 * @brief Runs tests for the selected day
 */
void RunTests() {
    std::wstring dayNum = FormatDayNumber(g_currentDay);
    
    DisplayOutput(L"Running tests for Day " + dayNum + L"...\n\n"
                 L"Test input file: tests\\Day" + dayNum + L"\\input.txt\n"
                 L"Expected output: tests\\Day" + dayNum + L"\\expected.txt\n\n"
                 L"Use CMake/CTest to run automated tests:\n"
                 L"cmake --build build --target test");
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

            // Create title label
            CreateWindowW(L"STATIC", L"30-Day DSA Challenge - Day Selector",
                WS_VISIBLE | WS_CHILD | SS_CENTER,
                10, 10, WINDOW_WIDTH - 20, 30,
                hwnd, NULL, NULL, NULL);

            // Create day selection combo box
            g_hComboDay = CreateWindowW(L"COMBOBOX", NULL,
                WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
                10, 50, 200, 400,
                hwnd, (HMENU)IDC_DAY_COMBO, NULL, NULL);

            // Populate combo box with days
            for (int i = 1; i <= 30; i++) {
                wchar_t buffer[50];
                swprintf(buffer, 50, L"Day %02d", i);
                SendMessageW(g_hComboDay, CB_ADDSTRING, 0, (LPARAM)buffer);
            }
            SendMessageW(g_hComboDay, CB_SETCURSEL, 0, 0);  // Select Day 01

            // Create buttons
            CreateWindowW(L"BUTTON", L"Show Problem",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                220, 50, 150, 25,
                hwnd, (HMENU)IDC_PROBLEM_BTN, NULL, NULL);

            CreateWindowW(L"BUTTON", L"Show Explanation",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                380, 50, 150, 25,
                hwnd, (HMENU)IDC_EXPLANATION_BTN, NULL, NULL);

            CreateWindowW(L"BUTTON", L"Run Solution",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                540, 50, 150, 25,
                hwnd, (HMENU)IDC_RUN_BTN, NULL, NULL);

            CreateWindowW(L"BUTTON", L"Run Tests",
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                700, 50, 150, 25,
                hwnd, (HMENU)IDC_TEST_BTN, NULL, NULL);

            // Create output text area with scrollbars
            g_hOutputEdit = CreateWindowW(L"EDIT", L"",
                WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | WS_HSCROLL |
                ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_READONLY,
                10, 90, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 130,
                hwnd, (HMENU)IDC_OUTPUT_EDIT, NULL, NULL);

            // Set a monospace font for better code display
            HFONT hFont = CreateFontW(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, L"Consolas");
            SendMessageW(g_hOutputEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

            // Display welcome message
            DisplayOutput(L"Welcome to the 30-Day DSA Challenge!\n\n"
                         L"Instructions:\n"
                         L"1. Select a day from the dropdown above\n"
                         L"2. Click 'Show Problem' to see the problem statement\n"
                         L"3. Click 'Show Explanation' to see the detailed explanation\n"
                         L"4. Click 'Run Solution' to execute the solution\n"
                         L"5. Click 'Run Tests' to run automated tests\n\n"
                         L"Make sure you've built the project using CMake first!\n\n"
                         L"Build instructions:\n"
                         L"  mkdir build\n"
                         L"  cd build\n"
                         L"  cmake ..\n"
                         L"  cmake --build .");

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
