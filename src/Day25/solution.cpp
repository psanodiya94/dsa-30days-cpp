#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary check and water/visited check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }

        // Mark as visited
        grid[i][j] = '0';

        // Explore 4 directions
        dfs(grid, i + 1, j);  // Down
        dfs(grid, i - 1, j);  // Up
        dfs(grid, i, j + 1);  // Right
        dfs(grid, i, j - 1);  // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);  // Mark entire island
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << sol.numIslands(grid) << endl;

    return 0;
}
