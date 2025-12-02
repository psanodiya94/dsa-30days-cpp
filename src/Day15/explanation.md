# Day 15: Reverse Linked List - Explanation

## Approach 1: Iterative (Three Pointers)

Use three pointers to reverse links one by one.

## Algorithm (Iterative)

1. Initialize `prev = nullptr`, `current = head`
2. While `current != nullptr`:
   - Save `next = current->next`
   - Reverse the link: `current->next = prev`
   - Move pointers: `prev = current`, `current = next`
3. Return `prev` (new head)

## Approach 2: Recursive

Recursively reverse the rest of the list, then fix current node's links.

## Algorithm (Recursive)

1. Base case: if head is null or only one node, return head
2. Recursively reverse the rest: `newHead = reverse(head->next)`
3. Fix links: `head->next->next = head`, `head->next = nullptr`
4. Return `newHead`

## Intuition

**Iterative approach**:
- Process nodes one by one
- For each node, reverse its next pointer
- Keep track of previous node to link to

**Visualizing the reversal**:
```
Original: 1 -> 2 -> 3 -> null
Step 1:   null <- 1    2 -> 3 -> null
Step 2:   null <- 1 <- 2    3 -> null
Step 3:   null <- 1 <- 2 <- 3
```

## Complexity Analysis

### Iterative:
- **Time Complexity**: O(n)
  - Visit each node once

- **Space Complexity**: O(1)
  - Only using three pointers

### Recursive:
- **Time Complexity**: O(n)
  - Visit each node once

- **Space Complexity**: O(n)
  - Recursion stack depth

## Example Walkthrough

```
Input: 1 -> 2 -> 3 -> null

Initial: prev=null, curr=1

Step 1:
  next = 2
  1->next = null
  prev = 1, curr = 2

Step 2:
  next = 3
  2->next = 1
  prev = 2, curr = 3

Step 3:
  next = null
  3->next = 2
  prev = 3, curr = null

Return prev (which is 3)
Result: 3 -> 2 -> 1 -> null
```
