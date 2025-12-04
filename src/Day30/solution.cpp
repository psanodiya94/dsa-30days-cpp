#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    // Method 1: Check each bit
    int hammingWeight1(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }

    // Method 2: Brian Kernighan's Algorithm (Optimal)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);  // Flip rightmost 1 bit
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    uint32_t n;
    cin >> n;

    cout << sol.hammingWeight(n) << endl;

    return 0;
}
