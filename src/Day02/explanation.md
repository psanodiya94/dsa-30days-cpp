# Day 02: Best Time to Buy and Sell Stock - Explanation

## Approach

### One-Pass Solution

Keep track of:
1. Minimum price seen so far (best buying point)
2. Maximum profit achievable

For each price, calculate profit if we sell today, and update maximum profit.

## Algorithm

1. Initialize `minPrice = infinity` and `maxProfit = 0`
2. For each price in the array:
   - Update `minPrice = min(minPrice, current price)`
   - Calculate potential profit: `current price - minPrice`
   - Update `maxProfit = max(maxProfit, potential profit)`
3. Return `maxProfit`

## Intuition

The key insight:
- We want to buy at the lowest price and sell at the highest price AFTER buying
- Track the minimum price seen so far (best buy opportunity)
- For each day, calculate profit if we sell today (after buying at minimum price)
- Keep track of the maximum profit seen

This works because we're always considering buying at the minimum price encountered before the current day.

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through the array

- **Space Complexity**: O(1)
  - Only using two variables

## Example Walkthrough

```
prices = [7, 1, 5, 3, 6, 4]

Day 0: price=7
  minPrice = 7, profit = 0, maxProfit = 0

Day 1: price=1
  minPrice = 1, profit = 0, maxProfit = 0

Day 2: price=5
  minPrice = 1, profit = 5-1 = 4, maxProfit = 4

Day 3: price=3
  minPrice = 1, profit = 3-1 = 2, maxProfit = 4

Day 4: price=6
  minPrice = 1, profit = 6-1 = 5, maxProfit = 5

Day 5: price=4
  minPrice = 1, profit = 4-1 = 3, maxProfit = 5

Result: 5
```
