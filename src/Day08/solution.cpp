#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    // Helper function to expand around center
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length of palindrome
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check odd-length palindromes (single character center)
            int len1 = expandAroundCenter(s, i, i);

            // Check even-length palindromes (two characters center)
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);

            // Update longest palindrome if current is longer
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;

    // Read input
    string s;
    getline(cin, s);

    // Solve and output
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}
