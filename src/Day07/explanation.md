# Day 07: Longest Substring Without Repeating Characters - Explanation

## Approach: Sliding Window + Hash Map

Use a sliding window with two pointers and track character positions in a hash map.

## Algorithm

1. Initialize `left = 0`, `maxLen = 0`, and an empty hash map
2. Iterate with `right` pointer from 0 to n-1:
   - If `s[right]` exists in map and its position >= left:
     - Move `left` to `map[s[right]] + 1` (skip the duplicate)
   - Update `map[s[right]] = right`
   - Update `maxLen = max(maxLen, right - left + 1)`
3. Return `maxLen`

## Intuition

**Sliding Window Technique**:
- Expand window by moving right pointer
- When duplicate found, shrink window from left
- Keep track of maximum window size

**Why use hash map?**
- Quick lookup to check if character exists
- Store last seen position of each character
- Helps us jump left pointer efficiently

**Key insight**:
- When we find a duplicate, we don't need to move left pointer one by one
- We can jump directly to the position after the previous occurrence

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass with right pointer
  - Each character visited at most twice (once by right, once by left)

- **Space Complexity**: O(min(n, m))
  - m is the character set size
  - Hash map stores at most m characters

## Example Walkthrough

```
s = "abcabcbb"

Step 1: right=0, s[0]='a'
  map = {a: 0}, left=0, maxLen=1

Step 2: right=1, s[1]='b'
  map = {a: 0, b: 1}, left=0, maxLen=2

Step 3: right=2, s[2]='c'
  map = {a: 0, b: 1, c: 2}, left=0, maxLen=3

Step 4: right=3, s[3]='a' (duplicate!)
  'a' at position 0 is in current window
  left = 0 + 1 = 1
  map = {a: 3, b: 1, c: 2}, maxLen=3

Step 5: right=4, s[4]='b' (duplicate!)
  'b' at position 1 is in current window
  left = 1 + 1 = 2
  map = {a: 3, b: 4, c: 2}, maxLen=3

... continue

Maximum length = 3 (substring "abc")
```
