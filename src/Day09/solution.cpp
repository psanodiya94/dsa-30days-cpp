#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            // Sort the string to use as key
            string key = str;
            sort(key.begin(), key.end());

            // Add original string to the group
            anagramGroups[key].push_back(str);
        }

        // Collect all groups
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Read input
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    // Solve
    vector<vector<string>> result = sol.groupAnagrams(strs);

    // Output
    for (const auto& group : result) {
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
