# Day 20: Binary Tree Level Order Traversal - Explanation

## Approach: BFS with Queue

Use a queue to process nodes level by level.

## Algorithm

1. If root is null, return empty list
2. Create a queue and add root
3. While queue is not empty:
   - Get current level size
   - For each node in current level:
     - Remove from queue
     - Add value to current level list
     - Add left child to queue (if exists)
     - Add right child to queue (if exists)
   - Add current level list to result
4. Return result

## Intuition

**BFS (Breadth-First Search)**:
- Process nodes level by level
- Use queue to maintain order
- Track level boundaries

**Why queue?**
- FIFO order ensures we process nodes in level order
- Left-to-right within each level

**Tracking levels**:
- Process all nodes at current level before moving to next
- Use queue size at start of iteration

## Complexity Analysis

- **Time Complexity**: O(n)
  - Visit each node exactly once

- **Space Complexity**: O(w)
  - w is maximum width of tree
  - Queue can hold up to one level at a time
  - Worst case: O(n) for perfect binary tree (last level has n/2 nodes)

## Example Walkthrough

```
Tree:
      3
     / \
    9  20
      /  \
     15   7

Level 0:
  Queue: [3]
  Process 3 → [[3]]
  Add children: Queue: [9, 20]

Level 1:
  Queue: [9, 20]
  Process 9, 20 → [[3], [9, 20]]
  Add children: Queue: [15, 7]

Level 2:
  Queue: [15, 7]
  Process 15, 7 → [[3], [9, 20], [15, 7]]
  No children

Result: [[3], [9, 20], [15, 7]]
```
