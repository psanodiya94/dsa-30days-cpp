# Day 18: Implement Queue using Stacks - Explanation

## Approach: Two Stacks

Use two stacks:
- `inStack`: for push operations
- `outStack`: for pop/peek operations

## Algorithm

**Push operation**:
1. Simply push to `inStack`
2. Time: O(1)

**Pop/Peek operations**:
1. If `outStack` is empty:
   - Transfer all elements from `inStack` to `outStack`
2. Pop/peek from `outStack`
3. Time: Amortized O(1)

**Empty check**:
1. Return true if both stacks are empty

## Intuition

**Why two stacks?**
- Stack is LIFO, Queue is FIFO
- Reversing a stack gives us FIFO order
- Transfer elements only when needed (lazy transfer)

**Example**:
```
Push 1, 2, 3:
inStack: [1, 2, 3] (top is 3)
outStack: []

Pop (need to get 1):
Transfer inStack to outStack:
inStack: []
outStack: [3, 2, 1] (top is 1)
Pop returns 1

Push 4:
inStack: [4]
outStack: [3, 2]

Pop:
outStack is not empty, pop from it
Returns 2
```

**Amortized O(1)**:
- Each element is moved at most twice (once to inStack, once to outStack)
- Total n operations on n elements: 2n moves
- Average: O(1) per operation

## Complexity Analysis

- **Time Complexity**:
  - Push: O(1)
  - Pop/Peek: Amortized O(1), worst case O(n)
  - Empty: O(1)

- **Space Complexity**: O(n)
  - Two stacks storing n elements total

## Visual Walkthrough

```
MyQueue q;

q.push(1):
  inStack: [1]
  outStack: []

q.push(2):
  inStack: [1, 2]
  outStack: []

q.peek():
  outStack is empty, transfer:
  inStack: []
  outStack: [2, 1]
  return top of outStack = 1

q.pop():
  outStack: [2, 1]
  return and remove top = 1
  outStack: [2]

q.empty():
  Both stacks have elements
  return false
```
