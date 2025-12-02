// dsa-30days-cpp.cpp : Defines the entry point for the application.
//

// Replace the problematic include directive with the necessary standard headers  
#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <vector>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <unordered_map>  
#include <unordered_set>  
#include <numeric>  

using namespace std;

// Forward declarations for each day's solve function
void solve_Day01();
void solve_Day02();
void solve_Day03();
void solve_Day04();
void solve_Day05();
void solve_Day06();
void solve_Day07();
void solve_Day08();
void solve_Day09();
void solve_Day10();
void solve_Day11();
void solve_Day12();
void solve_Day13();
void solve_Day14();
void solve_Day15();
void solve_Day16();
void solve_Day17();
void solve_Day18();
void solve_Day19();
void solve_Day20();
void solve_Day21();
void solve_Day22();
void solve_Day23();
void solve_Day24();
void solve_Day25();
void solve_Day26();
void solve_Day27();
void solve_Day28();
void solve_Day29();
void solve_Day30();

void run_with_file(const string& day) {
    string path = "../tests/" + day + "/input.txt";
    ifstream fin(path);
    if (!fin) {
        cerr << "Test input not found for " << day << " at " << path << "\n";
        cout << "Running interactively. Provide input on stdin.\n";
        // call function directly; it will read from cin
        if (day == "") return;
    }
    else {
        // redirect stdin to file
        auto oldbuf = cin.rdbuf(fin.rdbuf());
        if (day == "") { cin.rdbuf(oldbuf); return; }
        // dispatch
        string func = day;
        if (false) {}

        else if (day == "Day01") solve_Day01();
        else if (day == "Day02") solve_Day02();
        else if (day == "Day03") solve_Day03();
        else if (day == "Day04") solve_Day04();
        else if (day == "Day05") solve_Day05();
        else if (day == "Day06") solve_Day06();
        else if (day == "Day07") solve_Day07();
        else if (day == "Day08") solve_Day08();
        else if (day == "Day09") solve_Day09();
        else if (day == "Day10") solve_Day10();
        else if (day == "Day11") solve_Day11();
        else if (day == "Day12") solve_Day12();
        else if (day == "Day13") solve_Day13();
        else if (day == "Day14") solve_Day14();
        else if (day == "Day15") solve_Day15();
        else if (day == "Day16") solve_Day16();
        else if (day == "Day17") solve_Day17();
        else if (day == "Day18") solve_Day18();
        else if (day == "Day19") solve_Day19();
        else if (day == "Day20") solve_Day20();
        else if (day == "Day21") solve_Day21();
        else if (day == "Day22") solve_Day22();
        else if (day == "Day23") solve_Day23();
        else if (day == "Day24") solve_Day24();
        else if (day == "Day25") solve_Day25();
        else if (day == "Day26") solve_Day26();
        else if (day == "Day27") solve_Day27();
        else if (day == "Day28") solve_Day28();
        else if (day == "Day29") solve_Day29();
        else if (day == "Day30") solve_Day30();

        else { cerr << "Unknown day\n"; }
        // restore
        // Note: fin will close when out of scope, restore stdin
        // Restore is handled after this block by resetting cin's rdbuf
        // But since fin is a local variable, we need to copy its rdbuf back; we already saved oldbuf
        // restore:
        cin.rdbuf(nullptr); // reset to avoid dangling pointer; then set back to terminal
        // On many environments, setting to oldbuf is okay; attempt to set it
        // However, in MSVC this may behave differently; for Visual Studio, running via CMake's launch should work interactively.
        // Try to restore to default
        ios::sync_with_stdio(true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cout << "===== DSA 30 Days - Visual Studio Launcher =====\n";
        cout << "Select a day to run (1-30), 't' to run with test input, 'q' to quit:\n";
        cout << "Format: [day] or t[day] (e.g. 3  or t03) > ";
        string cmd;
        if (!(cin >> cmd)) break;
        if (cmd == "q" || cmd == "Q") break;
        bool useTest = false;
        string day;
        if (cmd.size() > 0 && (cmd[0] == 't' || cmd[0] == 'T')) {
            useTest = true;
            day = cmd.substr(1);
        }
        else {
            day = cmd;
        }
        // Normalize
        int dnum = 0;
        try { dnum = stoi(day); }
        catch (...) { cout << "Invalid input\n"; continue; }
        if (dnum < 1 || dnum > 30) { cout << "Day must be 1..30\n"; continue; }
        char buf[8];
        sprintf(buf, "Day%02d", dnum);
        string daystr(buf);
        if (useTest) {
            run_with_file(daystr);
        }
        else {
            // call directly; interactive run
            if (daystr == "") continue;
            else if (daystr == "Day01") solve_Day01();
            else if (daystr == "Day02") solve_Day02();
            else if (daystr == "Day03") solve_Day03();
            else if (daystr == "Day04") solve_Day04();
            else if (daystr == "Day05") solve_Day05();
            else if (daystr == "Day06") solve_Day06();
            else if (daystr == "Day07") solve_Day07();
            else if (daystr == "Day08") solve_Day08();
            else if (daystr == "Day09") solve_Day09();
            else if (daystr == "Day10") solve_Day10();
            else if (daystr == "Day11") solve_Day11();
            else if (daystr == "Day12") solve_Day12();
            else if (daystr == "Day13") solve_Day13();
            else if (daystr == "Day14") solve_Day14();
            else if (daystr == "Day15") solve_Day15();
            else if (daystr == "Day16") solve_Day16();
            else if (daystr == "Day17") solve_Day17();
            else if (daystr == "Day18") solve_Day18();
            else if (daystr == "Day19") solve_Day19();
            else if (daystr == "Day20") solve_Day20();
            else if (daystr == "Day21") solve_Day21();
            else if (daystr == "Day22") solve_Day22();
            else if (daystr == "Day23") solve_Day23();
            else if (daystr == "Day24") solve_Day24();
            else if (daystr == "Day25") solve_Day25();
            else if (daystr == "Day26") solve_Day26();
            else if (daystr == "Day27") solve_Day27();
            else if (daystr == "Day28") solve_Day28();
            else if (daystr == "Day29") solve_Day29();
            else if (daystr == "Day30") solve_Day30();

        }
        cout << "---- Done ----\n";
    }
    return 0;
}
