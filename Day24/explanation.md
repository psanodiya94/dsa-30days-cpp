# Day 24: Kth Largest Element - Explanation

## Approach 1: Min Heap (Size K)

Maintain a min heap of size k with k largest elements.

## Approach 2: Quickselect (Optimal)

Use partition like in quicksort to find kth largest in average O(n) time.

## Algorithm (Min Heap)

1. Create a min heap
2. Add first k elements to heap
3. For remaining elements:
   - If element > heap.top():
     - Remove heap.top()
     - Add element to heap
4. Return heap.top() (kth largest)

## Intuition

**Min Heap approach**:
- Keep k largest elements in heap
- Smallest of k largest is at top (kth largest overall)
- If we find larger element, remove smallest and add new one

**Why min heap not max heap?**
- We want the minimum of the k largest elements
- Min heap gives us that at the top

## Complexity Analysis

### Min Heap:
- **Time Complexity**: O(n log k)
  - Build heap: O(k log k)
  - Process n-k elements: O((n-k) log k)

- **Space Complexity**: O(k)
  - Heap size

### Quickselect:
- **Time Complexity**: O(n) average, O(n²) worst
- **Space Complexity**: O(1)

## Example Walkthrough

```
nums = [3,2,1,5,6,4], k = 2

Build heap with first 2 elements:
  heap = [2, 3]  (min heap)

Process 1:
  1 < 2 (heap.top), skip

Process 5:
  5 > 2, remove 2, add 5
  heap = [3, 5]

Process 6:
  6 > 3, remove 3, add 6
  heap = [5, 6]

Process 4:
  4 < 5, skip

heap.top() = 5 (2nd largest)
```
