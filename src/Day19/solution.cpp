#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        inorderHelper(node->left, result);   // Left
        result.push_back(node->val);         // Root
        inorderHelper(node->right, result);  // Right
    }

public:
    // Iterative approach
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            // Go left as far as possible
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Process node
            current = st.top();
            st.pop();
            result.push_back(current->val);

            // Move to right subtree
            current = current->right;
        }

        return result;
    }
};

// Helper to build tree from level-order (null as -1)
TreeNode* buildTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;

        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

int main() {
    Solution sol;

    int n;
    cin >> n;

    if (n == 0) {
        cout << endl;
        return 0;
    }

    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    TreeNode* root = buildTree(vals);
    vector<int> result = sol.inorderTraversal(root);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
