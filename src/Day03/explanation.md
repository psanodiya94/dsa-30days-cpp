# Day 03: Maximum Subarray - Explanation

## Approach: Kadane's Algorithm

This is a classic dynamic programming problem solved elegantly by Kadane's Algorithm.

## Algorithm

1. Initialize `maxSum = nums[0]` and `currentSum = 0`
2. For each number in the array:
   - Add current number to `currentSum`
   - Update `maxSum = max(maxSum, currentSum)`
   - If `currentSum < 0`, reset it to 0 (start fresh)
3. Return `maxSum`

## Intuition

The key insights:
- At each position, we decide: extend the existing subarray OR start a new subarray
- If the current sum becomes negative, it's better to start fresh
- We keep track of the maximum sum seen so far

**Why reset to 0 when sum becomes negative?**
- A negative sum will only decrease the sum of future elements
- It's better to start a new subarray from the next positive element

## Alternative Formulation

Think of it as: `currentSum = max(nums[i], currentSum + nums[i])`
- Either start a new subarray at current position
- Or extend the existing subarray

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through the array

- **Space Complexity**: O(1)
  - Only using two variables

## Example Walkthrough

```
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: num=-2
  currentSum = -2, maxSum = -2
  currentSum < 0, reset to 0

i=1: num=1
  currentSum = 1, maxSum = 1

i=2: num=-3
  currentSum = -2, maxSum = 1
  currentSum < 0, reset to 0

i=3: num=4
  currentSum = 4, maxSum = 4

i=4: num=-1
  currentSum = 3, maxSum = 4

i=5: num=2
  currentSum = 5, maxSum = 5

i=6: num=1
  currentSum = 6, maxSum = 6

i=7: num=-5
  currentSum = 1, maxSum = 6

i=8: num=4
  currentSum = 5, maxSum = 6

Result: 6 (subarray [4,-1,2,1])
```
