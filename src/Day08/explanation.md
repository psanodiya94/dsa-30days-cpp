# Day 08: Longest Palindromic Substring - Explanation

## Approach: Expand Around Center

For each possible center, expand outward while characters match.

## Algorithm

1. For each position in the string:
   - Treat it as center of odd-length palindrome (single character center)
   - Treat it as center of even-length palindrome (two characters center)
   - Expand outward while characters match
   - Track the longest palindrome found
2. Return the longest palindromic substring

## Intuition

**Key observations**:
- A palindrome mirrors around its center
- For odd-length palindromes: single character center (e.g., "aba")
- For even-length palindromes: empty center between two chars (e.g., "abba")

**Why expand around center?**
- Every palindrome has a center
- We can check all possible centers (2n-1 total: n single chars + n-1 between pairs)
- For each center, expand while left and right characters match

**Better than brute force**:
- Brute force: Check all O(n²) substrings, each check takes O(n) → O(n³)
- Expand around center: n centers, each expansion takes O(n) → O(n²)

## Complexity Analysis

- **Time Complexity**: O(n²)
  - n possible centers
  - Each expansion takes O(n) in worst case

- **Space Complexity**: O(1)
  - Only storing indices

## Alternative: Dynamic Programming
- Time: O(n²), Space: O(n²)
- `dp[i][j]` = true if substring from i to j is palindrome

## Example Walkthrough

```
s = "babad"

Center at index 0 ('b'):
  Odd: "b" (length 1)
  Even: no expansion

Center at index 1 ('a'):
  Odd: expand → "bab" (length 3) ✓
  Even: no match

Center at index 2 ('b'):
  Odd: expand → "aba" (length 3) ✓
  Even: no match

Center at index 3 ('a'):
  Odd: "a" (length 1)
  Even: no match

Center at index 4 ('d'):
  Odd: "d" (length 1)

Longest: "bab" or "aba" (both length 3)
```
