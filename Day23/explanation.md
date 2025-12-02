# Day 23: Search in Rotated Sorted Array - Explanation

## Approach: Modified Binary Search

Use binary search but determine which half is sorted.

## Algorithm

1. Initialize `left = 0`, `right = n - 1`
2. While `left <= right`:
   - Calculate `mid`
   - If `nums[mid] == target`: return mid
   - Determine which half is sorted:
     - If left half sorted (`nums[left] <= nums[mid]`):
       - If target in left range: search left
       - Else: search right
     - Else (right half sorted):
       - If target in right range: search right
       - Else: search left
3. Return -1

## Intuition

**Key insight**:
- At least one half is always sorted
- We can determine which half and check if target is in that range

**Rotated array properties**:
```
[4, 5, 6, 7, 0, 1, 2]
 ^sorted^    ^sorted^
```

**Decision making**:
1. Find which half is sorted
2. Check if target falls in sorted half's range
3. Eliminate half the array

## Complexity Analysis

- **Time Complexity**: O(log n)
  - Binary search with modified conditions

- **Space Complexity**: O(1)
  - Only using pointers

## Example Walkthrough

```
nums = [4,5,6,7,0,1,2], target = 0

Initial: left=0, right=6
  mid=3, nums[3]=7
  Left half [4,5,6,7] is sorted
  Target 0 not in [4,7]
  Search right: left=4

Step 2: left=4, right=6
  mid=5, nums[5]=1
  Right half [1,2] is sorted
  Target 0 not in [1,2]
  Search left: right=4

Step 3: left=4, right=4
  mid=4, nums[4]=0 == 0 ✓
  Found at index 4!
```
