#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex; // character -> last seen index
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If character is in map and within current window
            if (charIndex.find(currentChar) != charIndex.end() &&
                charIndex[currentChar] >= left) {
                // Move left pointer past the duplicate
                left = charIndex[currentChar] + 1;
            }

            // Update character's position
            charIndex[currentChar] = right;

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Read input
    string s;
    getline(cin, s);

    // Solve and output
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
