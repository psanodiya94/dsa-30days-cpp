#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (matching.count(c)) {
                // Check if stack is empty or top doesn't match
                if (st.empty() || st.top() != matching[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket
                st.push(c);
            }
        }

        // Valid if all brackets are matched (stack is empty)
        return st.empty();
    }
};

int main() {
    Solution sol;

    string s;
    getline(cin, s);

    cout << (sol.isValid(s) ? "true" : "false") << endl;

    return 0;
}
