#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Different lengths → not anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count frequencies
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Read input
    string s, t;
    cin >> s >> t;

    // Solve and output
    cout << (sol.isAnagram(s, t) ? "true" : "false") << endl;

    return 0;
}
