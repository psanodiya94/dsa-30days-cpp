# Day 21: Maximum Depth of Binary Tree - Explanation

## Approach 1: Recursive DFS

Recursively find maximum depth of left and right subtrees.

## Approach 2: Iterative BFS

Use level-order traversal to count levels.

## Algorithm (Recursive)

```
maxDepth(node):
    if node is null:
        return 0
    leftDepth = maxDepth(node.left)
    rightDepth = maxDepth(node.right)
    return 1 + max(leftDepth, rightDepth)
```

## Intuition

**Recursive thinking**:
- Depth of a tree = 1 + max(depth of left, depth of right)
- Base case: empty tree has depth 0
- Build up from leaves to root

**Why this works**:
- Each node adds 1 to the depth
- Take the longer path (left or right)

## Complexity Analysis

### Recursive:
- **Time Complexity**: O(n)
  - Visit each node once

- **Space Complexity**: O(h)
  - Recursion stack, h is height
  - Worst case: O(n) for skewed tree

### Iterative BFS:
- **Time Complexity**: O(n)
- **Space Complexity**: O(w)
  - w is maximum width

## Example Walkthrough

```
Tree:
      3
     / \
    9  20
      /  \
     15   7

maxDepth(3):
  maxDepth(9) = 1 (leaf)
  maxDepth(20):
    maxDepth(15) = 1
    maxDepth(7) = 1
    return 1 + max(1, 1) = 2
  return 1 + max(1, 2) = 3
```
