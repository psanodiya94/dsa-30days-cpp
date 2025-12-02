# Day 12: 3Sum - Explanation

## Approach: Sort + Two Pointers

Sort the array, then for each element, use two pointers to find pairs that sum to negative of that element.

## Algorithm

1. Sort the array
2. For each index `i` from 0 to n-3:
   - Skip duplicates for i
   - Set `target = -nums[i]`
   - Use two pointers: `left = i + 1`, `right = n - 1`
   - While `left < right`:
     - If `nums[left] + nums[right] == target`:
       - Add triplet to result
       - Skip duplicates for left and right
       - Move both pointers
     - If sum < target: move left++
     - If sum > target: move right--
3. Return result

## Intuition

**Breaking down the problem**:
- 3Sum reduces to: for each number, find two numbers that sum to its negative
- This becomes a 2Sum problem (which we solve with two pointers)

**Why sort first?**
- Allows us to use two pointers efficiently
- Makes it easy to skip duplicates
- Helps avoid duplicate triplets

**Avoiding duplicates**:
- Skip duplicate values for i, left, and right pointers
- Sorting ensures duplicates are adjacent

## Complexity Analysis

- **Time Complexity**: O(n²)
  - Sorting: O(n log n)
  - For each element: O(n) two-pointer search
  - Total: O(n²)

- **Space Complexity**: O(1) or O(n)
  - Ignoring the output array
  - Sorting may use O(log n) or O(n) space

## Example Walkthrough

```
nums = [-1, 0, 1, 2, -1, -4]

After sorting: [-4, -1, -1, 0, 1, 2]

i=0, nums[0]=-4, target=4:
  left=1, right=5: -1+2=1 < 4, move left
  left=2, right=5: -1+2=1 < 4, move left
  left=3, right=5: 0+2=2 < 4, move left
  left=4, right=5: 1+2=3 < 4, move left
  No triplet found

i=1, nums[1]=-1, target=1:
  left=2, right=5: -1+2=1 ✓
  Found: [-1, -1, 2]
  Skip duplicate at index 2
  left=3, right=4: 0+1=1 ✓
  Found: [-1, 0, 1]

i=2: skip (duplicate -1)

i=3, nums[3]=0, target=0:
  left=4, right=5: 1+2=3 > 0, no matches

Result: [[-1,-1,2], [-1,0,1]]
```
