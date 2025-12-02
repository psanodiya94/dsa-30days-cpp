// ============================================================================
// Day 01: Two Sum - Hash Map Approach
// ============================================================================
// Problem: Given an array of integers and a target sum, find two numbers
//          that add up to the target and return their indices.
//
// Approach: Use a hash map to store seen numbers and their indices.
//           For each number, check if its complement (target - number) exists.
//
// Time Complexity: O(n) - Single pass through array
// Space Complexity: O(n) - Hash map stores up to n elements
// ============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ============================================================================
// Solution Class
// ============================================================================

class Solution {
public:
    /**
     * @brief Finds two numbers in array that sum to target
     *
     * This function uses a hash map approach to find the solution in O(n) time.
     * As we iterate through the array, we:
     * 1. Calculate the complement needed (target - current number)
     * 2. Check if we've seen this complement before
     * 3. If yes, return the indices; if no, store current number
     *
     * @param nums Vector of integers to search
     * @param target The target sum we're looking for
     * @return Vector containing two indices where nums[i] + nums[j] = target
     *
     * Example:
     *   Input: nums = [2, 7, 11, 15], target = 9
     *   Output: [0, 1]
     *   Explanation: nums[0] + nums[1] = 2 + 7 = 9
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store: {number_value -> index_in_array}
        // This allows O(1) lookup to check if complement exists
        unordered_map<int, int> numMap;

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate what number we need to reach the target
            // If current number is 2 and target is 9, we need 7
            int complement = target - nums[i];

            // Check if we've already seen the complement in our map
            // find() returns map.end() if element not found
            if (numMap.find(complement) != numMap.end()) {
                // Found it! Return the stored index of complement and current index
                // The complement was seen earlier, so its index comes first
                return {numMap[complement], i};
            }

            // We haven't found the pair yet
            // Store current number and its index for future lookups
            // This way, if we encounter its complement later, we can find it
            numMap[nums[i]] = i;
        }

        // No solution found (this shouldn't happen per problem constraints)
        // Problem guarantees exactly one solution exists
        return {};
    }
};

// ============================================================================
// Main Function - Input/Output Handling
// ============================================================================

/**
 * @brief Main entry point for the program
 *
 * Input format:
 *   Line 1: n (size of array), target (target sum)
 *   Line 2: n space-separated integers (the array elements)
 *
 * Output format:
 *   Two space-separated indices
 *
 * Example:
 *   Input:
 *     4 9
 *     2 7 11 15
 *   Output:
 *     0 1
 */
int main() {
    // Create an instance of our Solution class
    Solution sol;

    // ========================================================================
    // Input Reading
    // ========================================================================

    int n;      // Number of elements in array
    int target; // Target sum we're looking for

    // Read array size and target sum
    cin >> n >> target;

    // Create vector to store array elements
    vector<int> nums(n);

    // Read n integers into the vector
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // ========================================================================
    // Solution Execution
    // ========================================================================

    // Call our twoSum function to find the indices
    vector<int> result = sol.twoSum(nums, target);

    // ========================================================================
    // Output
    // ========================================================================

    // Print the two indices separated by space
    // result[0] is the index of the first number
    // result[1] is the index of the second number
    cout << result[0] << " " << result[1] << endl;

    return 0;  // Program completed successfully
}

// ============================================================================
// Algorithm Walkthrough Example
// ============================================================================
//
// Input: nums = [2, 7, 11, 15], target = 9
//
// Iteration 1 (i=0, nums[0]=2):
//   complement = 9 - 2 = 7
//   Check map: {} (empty, 7 not found)
//   Add to map: {2 -> 0}
//
// Iteration 2 (i=1, nums[1]=7):
//   complement = 9 - 7 = 2
//   Check map: {2 -> 0} (found 2!)
//   Return [0, 1]
//
// Output: [0, 1]
//
// ============================================================================
// Why This Approach is Optimal
// ============================================================================
//
// Brute Force (Nested Loops):
//   - Check every pair (i, j)
//   - Time: O(n²), Space: O(1)
//   - Inefficient for large arrays
//
// Hash Map Approach (This Solution):
//   - Single pass with O(1) lookup
//   - Time: O(n), Space: O(n)
//   - Much faster for large arrays
//   - Trade space for time (common optimization strategy)
//
// ============================================================================
