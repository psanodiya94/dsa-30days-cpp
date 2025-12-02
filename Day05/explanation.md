# Day 05: Container With Most Water - Explanation

## Approach: Two Pointers

Use two pointers starting from both ends and move them towards each other.

## Algorithm

1. Initialize `left = 0`, `right = n - 1`, `maxArea = 0`
2. While `left < right`:
   - Calculate area: `min(height[left], height[right]) * (right - left)`
   - Update `maxArea` if current area is larger
   - Move the pointer with smaller height inward
     - If `height[left] < height[right]`: move `left++`
     - Else: move `right--`
3. Return `maxArea`

## Intuition

**Why start from both ends?**
- We want to maximize both width and height
- Starting from ends gives maximum width
- We gradually reduce width while trying to find taller lines

**Why move the shorter pointer?**
- Area is limited by the shorter line
- Moving the taller pointer won't help (area can only decrease)
- Moving the shorter pointer gives a chance to find a taller line

**Key insight**:
- Area = `min(height[left], height[right]) × width`
- Width decreases as we move pointers inward
- So we need to find taller lines to compensate

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass with two pointers

- **Space Complexity**: O(1)
  - Only using a few variables

## Example Walkthrough

```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
indices:  0  1  2  3  4  5  6  7  8

Initial: left=0, right=8
  area = min(1, 7) × 8 = 1 × 8 = 8
  height[0] < height[8], move left++

left=1, right=8
  area = min(8, 7) × 7 = 7 × 7 = 49 ← maximum!
  height[8] < height[1], move right--

left=1, right=7
  area = min(8, 3) × 6 = 3 × 6 = 18
  height[7] < height[1], move right--

... continue until left >= right

Maximum area = 49
```
