# Day 29: Longest Common Subsequence - Explanation

## Approach: 2D Dynamic Programming

Classic 2D DP problem.

## Algorithm

1. Create `dp[m+1][n+1]` where m, n are string lengths
2. Initialize first row and column to 0
3. For i from 1 to m:
   - For j from 1 to n:
     - If `text1[i-1] == text2[j-1]`:
       - `dp[i][j] = dp[i-1][j-1] + 1`
     - Else:
       - `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
4. Return `dp[m][n]`

## Intuition

**DP state**:
- `dp[i][j]` = LCS length of `text1[0...i-1]` and `text2[0...j-1]`

**Recurrence**:
- If characters match: include them → `dp[i-1][j-1] + 1`
- If don't match: take best of excluding one character:
  - Exclude from text1: `dp[i-1][j]`
  - Exclude from text2: `dp[i][j-1]`

**Building up the solution**:
- Start from empty strings (base case: 0)
- Build up to full strings

## Complexity Analysis

- **Time Complexity**: O(m × n)
  - Fill m×n table

- **Space Complexity**: O(m × n)
  - DP table
  - Can be optimized to O(min(m, n))

## Example Walkthrough

```
text1 = "abcde", text2 = "ace"

    ""  a  c  e
""   0  0  0  0
a    0  1  1  1
b    0  1  1  1
c    0  1  2  2
d    0  1  2  2
e    0  1  2  3

dp[5][3] = 3
LCS = "ace"
```

**Step by step**:
- (a,a): match! dp[1][1] = dp[0][0] + 1 = 1
- (a,c): no match, dp[1][2] = max(dp[0][2], dp[1][1]) = 1
- (b,a): no match, dp[2][1] = max(dp[1][1], dp[2][0]) = 1
- (c,c): match! dp[3][2] = dp[2][1] + 1 = 2
- (e,e): match! dp[5][3] = dp[4][2] + 1 = 3
