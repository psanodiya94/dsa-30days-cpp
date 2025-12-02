#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use min heap to keep top k elements
        // Pair: {frequency, number}
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first; // Min heap based on frequency
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (auto& p : freq) {
            minHeap.push({p.second, p.first}); // {frequency, number}

            if (minHeap.size() > k) {
                minHeap.pop(); // Remove least frequent
            }
        }

        // Step 3: Extract results
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Read input
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Solve
    vector<int> result = sol.topKFrequent(nums, k);

    // Output
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
