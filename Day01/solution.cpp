#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            // Add current number to map
            numMap[nums[i]] = i;
        }

        return {}; // No solution found (shouldn't happen per problem constraints)
    }
};

int main() {
    Solution sol;

    // Read input
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Solve
    vector<int> result = sol.twoSum(nums, target);

    // Output
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
