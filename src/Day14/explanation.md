# Day 14: Longest Repeating Character Replacement - Explanation

## Approach: Sliding Window

Use sliding window to track the longest valid substring where we can make all characters same with at most k replacements.

## Algorithm

1. Use two pointers: `left = 0`, `right = 0`
2. Track character frequencies in current window
3. Track `maxFreq` (most frequent character count in window)
4. For each position:
   - Add `s[right]` to window
   - Update `maxFreq`
   - If `windowSize - maxFreq > k`: shrink window from left
   - Update result with current window size
5. Return maximum window size found

## Intuition

**Key insight**:
- In a window, we need at most `windowSize - maxFreq` replacements
- If this exceeds `k`, the window is invalid

**Why this works**:
- We want to replace all characters to match the most frequent one
- Number of replacements = total characters - most frequent character count
- If we need more than k replacements, shrink window

**Optimization**:
- We don't need to decrement `maxFreq` when shrinking
- Because we only care about windows larger than current best

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass with sliding window
  - Character count operations are O(1) (at most 26 letters)

- **Space Complexity**: O(1)
  - Fixed size character frequency array (26 letters)

## Example Walkthrough

```
s = "AABABBA", k = 1

Window [0,0]: "A", maxFreq=1, need 0 replacements ✓
Window [0,1]: "AA", maxFreq=2, need 0 replacements ✓
Window [0,2]: "AAB", maxFreq=2, need 1 replacement ✓
Window [0,3]: "AABA", maxFreq=3, need 1 replacement ✓
Window [0,4]: "AABAB", maxFreq=3, need 2 replacements ✗
  Shrink: left=1
Window [1,4]: "ABAB", maxFreq=2, need 2 replacements ✗
  Shrink: left=2
Window [2,4]: "BAB", maxFreq=2, need 1 replacement ✓
Window [2,5]: "BABB", maxFreq=3, need 1 replacement ✓
Window [2,6]: "BABBA", maxFreq=3, need 2 replacements ✗
  Shrink: left=3
Window [3,6]: "ABBA", maxFreq=2, need 2 replacements ✗
  Shrink: left=4
Window [4,6]: "BBA", maxFreq=2, need 1 replacement ✓

Maximum: 4
```
