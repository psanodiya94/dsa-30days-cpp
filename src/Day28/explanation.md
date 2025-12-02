# Day 28: Coin Change - Explanation

## Approach: Dynamic Programming (Bottom-Up)

Build up solutions for amounts from 0 to target amount.

## Algorithm

1. Create `dp` array of size `amount + 1`
2. Initialize `dp[0] = 0` (0 coins for amount 0)
3. Initialize rest to infinity
4. For each amount from 1 to target:
   - For each coin:
     - If coin <= amount:
       - `dp[amount] = min(dp[amount], dp[amount - coin] + 1)`
5. Return `dp[amount]` if valid, else -1

## Intuition

**DP recurrence**:
- To make amount `i`, we can use any coin `c` where `c <= i`
- After using coin `c`, we need `dp[i - c]` more coins
- Total: `dp[i - c] + 1` coins
- Take minimum across all coin choices

**Example**:
```
coins = [1, 2, 5], amount = 11

dp[0] = 0
dp[1] = 1 (use coin 1)
dp[2] = 1 (use coin 2)
dp[3] = 2 (2+1 or 1+1+1)
dp[4] = 2 (2+2)
dp[5] = 1 (use coin 5)
dp[6] = 2 (5+1)
...
dp[11] = 3 (5+5+1)
```

## Complexity Analysis

- **Time Complexity**: O(amount × coins.length)
  - For each amount, try each coin

- **Space Complexity**: O(amount)
  - DP array

## Example Walkthrough

```
coins = [1, 2, 5], amount = 11

dp[0] = 0

dp[1]:
  coin 1: dp[1-1] + 1 = dp[0] + 1 = 1
  dp[1] = 1

dp[2]:
  coin 1: dp[2-1] + 1 = dp[1] + 1 = 2
  coin 2: dp[2-2] + 1 = dp[0] + 1 = 1
  dp[2] = min(2, 1) = 1

...

dp[11]:
  coin 1: dp[10] + 1 = 3 + 1 = 4
  coin 2: dp[9] + 1 = 3 + 1 = 4
  coin 5: dp[6] + 1 = 2 + 1 = 3
  dp[11] = min(4, 4, 3) = 3
```
