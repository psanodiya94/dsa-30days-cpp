#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Create DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Characters don't match
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    string text1, text2;
    cin >> text1 >> text2;

    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
