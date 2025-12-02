# Day 22: Binary Search - Explanation

## Approach: Classic Binary Search

Repeatedly divide search space in half.

## Algorithm

1. Initialize `left = 0`, `right = n - 1`
2. While `left <= right`:
   - Calculate `mid = left + (right - left) / 2`
   - If `nums[mid] == target`: return mid
   - If `nums[mid] < target`: search right half (left = mid + 1)
   - If `nums[mid] > target`: search left half (right = mid - 1)
3. Return -1 (not found)

## Intuition

**Why binary search?**
- Array is sorted
- Can eliminate half the elements with each comparison
- Much faster than linear search for large arrays

**Key points**:
- Use `left + (right - left) / 2` to avoid integer overflow
- Update boundaries correctly (mid + 1 or mid - 1)
- Loop condition: `left <= right`

## Complexity Analysis

- **Time Complexity**: O(log n)
  - Halve search space each iteration
  - At most log₂(n) iterations

- **Space Complexity**: O(1)
  - Only using a few variables

## Example Walkthrough

```
nums = [-1,0,3,5,9,12], target = 9

Initial: left=0, right=5
  mid=2, nums[2]=3 < 9
  Search right: left=3, right=5

Step 2: left=3, right=5
  mid=4, nums[4]=9 == 9 ✓
  Found at index 4!
```
