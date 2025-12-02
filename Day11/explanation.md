# Day 11: Valid Palindrome - Explanation

## Approach: Two Pointers

Use two pointers from both ends, skipping non-alphanumeric characters.

## Algorithm

1. Initialize `left = 0`, `right = n - 1`
2. While `left < right`:
   - Skip non-alphanumeric characters from left
   - Skip non-alphanumeric characters from right
   - Compare lowercase versions of characters
   - If they don't match, return false
   - Move both pointers inward
3. Return true (all characters matched)

## Intuition

**Two Pointers Technique**:
- Start from both ends
- Move towards center
- Compare corresponding characters
- Skip non-alphanumeric characters

**Why this works**:
- Palindrome reads same from both directions
- We only need to check valid characters
- No need to create a new string (saves space)

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass with two pointers
  - Each character visited at most once

- **Space Complexity**: O(1)
  - Only using two pointers
  - No extra data structures

## Example Walkthrough

```
s = "A man, a plan, a canal: Panama"

Convert and filter: "amanaplanacanalpanama"

left=0, right=22: 'a' == 'a' ✓
left=1, right=21: 'm' == 'm' ✓
left=2, right=20: 'a' == 'a' ✓
...
All characters match → true
```
