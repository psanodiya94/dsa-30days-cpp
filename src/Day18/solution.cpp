#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;   // For push operations
    stack<int> outStack;  // For pop/peek operations

    // Transfer elements from inStack to outStack
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            transfer();
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int peek() {
        if (outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            q.push(x);
            cout << "null" << endl;
        } else if (operation == "pop") {
            cout << q.pop() << endl;
        } else if (operation == "peek") {
            cout << q.peek() << endl;
        } else if (operation == "empty") {
            cout << (q.empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}
