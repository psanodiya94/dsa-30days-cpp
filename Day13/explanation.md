# Day 13: Minimum Window Substring - Explanation

## Approach: Sliding Window with Hash Map

Expand window until all characters from `t` are included, then contract to find minimum.

## Algorithm

1. Count character frequencies in `t`
2. Use two pointers: `left = 0`, `right = 0`
3. Expand `right` until window contains all characters:
   - Add `s[right]` to window
   - If character is needed, decrement required count
4. Once valid, contract `left` to minimize:
   - Update minimum window if current is smaller
   - Remove `s[left]` from window
   - Move `left++`
5. Return minimum window found

## Intuition

**Sliding Window Pattern**:
- Expand right to include more characters
- Contract left to minimize window size
- Track whether window is valid (contains all of t)

**Using counters**:
- `required`: total characters we need from t
- `formed`: how many required characters we currently have
- Window is valid when `formed == required`

## Complexity Analysis

- **Time Complexity**: O(m + n)
  - m is length of s, n is length of t
  - Each character visited at most twice (right and left pointers)

- **Space Complexity**: O(m + n)
  - Hash maps for character frequencies

## Example Walkthrough

```
s = "ADOBECODEBANC", t = "ABC"

Target: A=1, B=1, C=1

Expand until valid:
right=0-5: "ADOBEC" (has A, B, C) ✓

Contract from left:
"DOBEC" (missing A) ✗
So "ADOBEC" is a candidate

Continue expanding and contracting...
Final minimum: "BANC"
```
