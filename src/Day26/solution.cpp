#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& state) {
        if (state[course] == 1) {
            return false;  // Cycle detected (visiting node)
        }
        if (state[course] == 2) {
            return true;   // Already visited
        }

        state[course] = 1;  // Mark as visiting

        // Visit all prerequisites
        for (int prereq : adj[course]) {
            if (!dfs(prereq, adj, state)) {
                return false;
            }
        }

        state[course] = 2;  // Mark as visited
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (const auto& prereq : prerequisites) {
            adj[prereq[0]].push_back(prereq[1]);
        }

        // State: 0=unvisited, 1=visiting, 2=visited
        vector<int> state(numCourses, 0);

        // Check for cycles starting from each course
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) {
                    return false;  // Cycle found
                }
            }
        }

        return true;  // No cycles
    }
};

int main() {
    Solution sol;

    int numCourses, numPrereqs;
    cin >> numCourses >> numPrereqs;

    vector<vector<int>> prerequisites(numPrereqs, vector<int>(2));
    for (int i = 0; i < numPrereqs; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    return 0;
}
