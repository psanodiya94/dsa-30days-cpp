# Day 10: Top K Frequent Elements - Explanation

## Approach 1: Hash Map + Min Heap

Use hash map to count frequencies, then use a min heap of size k.

## Approach 2: Hash Map + Bucket Sort (Optimal)

Use frequency as index in bucket array.

## Algorithm (Heap Approach)

1. Count frequencies using hash map
2. Use a min heap of size k:
   - Add first k elements
   - For remaining elements, if frequency > heap.top():
     - Remove heap.top()
     - Add current element
3. Extract all elements from heap

## Algorithm (Bucket Sort - O(n))

1. Count frequencies using hash map
2. Create buckets: `bucket[frequency] = list of elements`
3. Iterate buckets from highest frequency to lowest
4. Collect k elements

## Intuition

**Heap Approach**:
- We only need top k elements
- Min heap of size k keeps track of k most frequent
- If we find higher frequency, remove minimum and add new

**Bucket Sort Approach**:
- Frequency range: 1 to n
- Create n+1 buckets indexed by frequency
- Collect from highest frequency first

## Complexity Analysis

### Heap Approach:
- **Time Complexity**: O(n log k)
  - Count frequencies: O(n)
  - Heap operations: O(n log k)

- **Space Complexity**: O(n + k)
  - Hash map: O(n)
  - Heap: O(k)

### Bucket Sort Approach:
- **Time Complexity**: O(n)
  - Count frequencies: O(n)
  - Fill buckets: O(n)
  - Collect results: O(n)

- **Space Complexity**: O(n)

## Example Walkthrough

```
nums = [1,1,1,2,2,3], k = 2

Step 1: Count frequencies
  freq = {1: 3, 2: 2, 3: 1}

Step 2 (Bucket approach):
  bucket[1] = [3]
  bucket[2] = [2]
  bucket[3] = [1]

Step 3: Collect from highest frequency
  From bucket[3]: add 1
  From bucket[2]: add 2
  We have k=2 elements

Result: [1, 2]
```
