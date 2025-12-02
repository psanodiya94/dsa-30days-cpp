#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative approach
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* next = current->next; // Save next node
            current->next = prev;           // Reverse link
            prev = current;                 // Move prev forward
            current = next;                 // Move current forward
        }

        return prev; // New head
    }

    // Recursive approach (alternative)
    ListNode* reverseListRecursive(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursively reverse the rest
        ListNode* newHead = reverseListRecursive(head->next);

        // Fix links
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

// Helper functions
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;

    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " ";
        head = head->next;
    }
    cout << endl;
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

    ListNode* head = createList(vals);
    head = sol.reverseList(head);
    printList(head);

    return 0;
}
