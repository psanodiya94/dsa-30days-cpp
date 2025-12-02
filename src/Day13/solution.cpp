#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Count characters in t
        unordered_map<char, int> targetCount;
        for (char c : t) {
            targetCount[c]++;
        }

        int required = targetCount.size(); // Unique characters in t
        int formed = 0; // Unique characters in current window with desired frequency

        unordered_map<char, int> windowCount;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;

        while (right < s.length()) {
            // Expand window
            char c = s[right];
            windowCount[c]++;

            // Check if frequency of current char matches desired count
            if (targetCount.count(c) && windowCount[c] == targetCount[c]) {
                formed++;
            }

            // Contract window while valid
            while (formed == required && left <= right) {
                // Update result if this window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Shrink window from left
                char leftChar = s[left];
                windowCount[leftChar]--;
                if (targetCount.count(leftChar) && windowCount[leftChar] < targetCount[leftChar]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;

    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << sol.minWindow(s, t) << endl;

    return 0;
}
