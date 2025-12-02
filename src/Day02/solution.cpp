#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Update minimum price seen so far
            minPrice = min(minPrice, price);

            // Calculate profit if we sell today
            int profit = price - minPrice;

            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;

    // Read input
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Solve and output
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
