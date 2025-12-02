# Day 19: Binary Tree Inorder Traversal - Explanation

## Inorder Traversal Order

For each node:
1. Visit left subtree
2. Visit current node
3. Visit right subtree

Result: **Left → Root → Right**

## Approach 1: Recursive

Simple recursive implementation following the definition.

## Approach 2: Iterative (Using Stack)

Use a stack to simulate the recursive call stack.

## Algorithm (Recursive)

```
inorder(node):
    if node is null:
        return
    inorder(node.left)
    result.add(node.val)
    inorder(node.right)
```

## Algorithm (Iterative)

1. Initialize empty stack and current = root
2. While stack is not empty OR current is not null:
   - Go left as far as possible, pushing nodes to stack
   - Pop node from stack
   - Add node value to result
   - Move to right child
3. Return result

## Intuition

**Why inorder?**
- For Binary Search Trees, inorder gives sorted order
- Common traversal pattern in tree problems

**Iterative approach**:
- Use stack to track nodes while going left
- When can't go left, process node and go right

## Complexity Analysis

### Both approaches:
- **Time Complexity**: O(n)
  - Visit each node exactly once

- **Space Complexity**: O(h)
  - h is tree height
  - Recursion stack or explicit stack
  - Worst case: O(n) for skewed tree

## Example Walkthrough

```
Tree:
    1
     \
      2
     /
    3

Inorder: Left → Root → Right

Visit 1:
  Left of 1: null
  Process 1 → [1]
  Right of 1: go to 2

Visit 2:
  Left of 2: go to 3

Visit 3:
  Left of 3: null
  Process 3 → [1, 3]
  Right of 3: null

Back to 2:
  Process 2 → [1, 3, 2]

Result: [1, 3, 2]
```
