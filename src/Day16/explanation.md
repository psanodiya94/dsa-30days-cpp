# Day 16: Merge Two Sorted Lists - Explanation

## Approach 1: Iterative (Dummy Node)

Use a dummy node to build the merged list.

## Algorithm (Iterative)

1. Create a dummy node
2. Use `current` pointer starting at dummy
3. While both lists have nodes:
   - Compare values of list1 and list2
   - Link smaller node to current
   - Move pointer of the list we took from
   - Move current pointer
4. Attach remaining nodes from non-empty list
5. Return `dummy->next`

## Approach 2: Recursive

Recursively choose the smaller node and merge the rest.

## Intuition

**Merge process**:
- Similar to merge step in merge sort
- Always pick the smaller value from two lists
- Continue until one list is exhausted

**Dummy node trick**:
- Simplifies edge cases (empty lists)
- Avoids special handling for first node
- Final result is `dummy->next`

## Complexity Analysis

### Iterative:
- **Time Complexity**: O(n + m)
  - Visit each node in both lists once
  - n and m are lengths of the two lists

- **Space Complexity**: O(1)
  - Only using a few pointers

### Recursive:
- **Time Complexity**: O(n + m)
  - Visit each node once

- **Space Complexity**: O(n + m)
  - Recursion stack depth

## Example Walkthrough

```
list1 = 1 -> 2 -> 4
list2 = 1 -> 3 -> 4

dummy -> ?

Step 1: Compare 1 and 1, take from list1
dummy -> 1 (from list1)
list1 = 2 -> 4

Step 2: Compare 2 and 1, take from list2
dummy -> 1 -> 1 (from list2)
list2 = 3 -> 4

Step 3: Compare 2 and 3, take from list1
dummy -> 1 -> 1 -> 2
list1 = 4

Step 4: Compare 4 and 3, take from list2
dummy -> 1 -> 1 -> 2 -> 3
list2 = 4

Step 5: Compare 4 and 4, take from list1
dummy -> 1 -> 1 -> 2 -> 3 -> 4
list1 = null

Step 6: Attach remaining list2
dummy -> 1 -> 1 -> 2 -> 3 -> 4 -> 4

Result: 1 -> 1 -> 2 -> 3 -> 4 -> 4
```
