#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // Add current character to window
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);

            // Check if window is valid
            int windowSize = right - left + 1;
            int replacements = windowSize - maxFreq;

            if (replacements > k) {
                // Shrink window from left
                count[s[left]]--;
                left++;
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s;
    int k;
    cin >> s >> k;

    cout << sol.characterReplacement(s, k) << endl;

    return 0;
}
