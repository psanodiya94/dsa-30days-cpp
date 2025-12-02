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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach remaining nodes
        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }

    // Recursive approach (alternative)
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
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
    if (head == nullptr) {
        cout << endl;
        return;
    }

    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    int n1, n2;
    cin >> n1;

    ListNode* list1 = nullptr;
    if (n1 > 0) {
        vector<int> vals1(n1);
        for (int i = 0; i < n1; i++) {
            cin >> vals1[i];
        }
        list1 = createList(vals1);
    }

    cin >> n2;
    ListNode* list2 = nullptr;
    if (n2 > 0) {
        vector<int> vals2(n2);
        for (int i = 0; i < n2; i++) {
            cin >> vals2[i];
        }
        list2 = createList(vals2);
    }

    ListNode* merged = sol.mergeTwoLists(list1, list2);
    printList(merged);

    return 0;
}
