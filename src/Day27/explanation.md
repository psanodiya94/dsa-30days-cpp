# Day 27: Climbing Stairs - Explanation

## Approach: Dynamic Programming (Fibonacci Pattern)

This is essentially the Fibonacci sequence.

## Algorithm

1. Base cases: `dp[1] = 1`, `dp[2] = 2`
2. For i from 3 to n:
   - `dp[i] = dp[i-1] + dp[i-2]`
3. Return `dp[n]`

**Optimized (Space O(1))**:
- Only keep track of last two values

## Intuition

**Recurrence relation**:
- To reach step n, we can come from:
  - Step n-1 (take 1 step)
  - Step n-2 (take 2 steps)
- Therefore: `ways(n) = ways(n-1) + ways(n-2)`

**This is Fibonacci!**
```
n=1: 1 way (1)
n=2: 2 ways (1+1, 2)
n=3: 3 ways (1+1+1, 1+2, 2+1)
n=4: 5 ways
...
```

## Complexity Analysis

### DP Array:
- **Time Complexity**: O(n)
  - Compute each value once

- **Space Complexity**: O(n)
  - DP array

### Space Optimized:
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
  - Only two variables

## Example Walkthrough

```
n = 5

dp[1] = 1
dp[2] = 2
dp[3] = dp[1] + dp[2] = 1 + 2 = 3
dp[4] = dp[2] + dp[3] = 2 + 3 = 5
dp[5] = dp[3] + dp[4] = 3 + 5 = 8

Result: 8 ways
```
