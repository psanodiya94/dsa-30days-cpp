# Day 01: Two Sum - Explanation

## Approach

### Brute Force (Not Recommended)
Check every pair of numbers - O(n²) time complexity.

### Optimal: Hash Map Approach

The key insight is to use a hash map to store numbers we've seen along with their indices. For each number, we check if `target - current_number` exists in our hash map.

## Algorithm

1. Create an empty hash map to store `{value -> index}`
2. Iterate through the array:
   - Calculate `complement = target - nums[i]`
   - If complement exists in hash map, return `[map[complement], i]`
   - Otherwise, add current number to hash map: `map[nums[i]] = i`
3. Return result

## Intuition

Instead of checking all pairs, we can:
- For each number `x`, we need to find if `target - x` exists
- Hash map gives us O(1) lookup time
- Single pass through the array is sufficient

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through the array
  - Hash map operations (insert/lookup) are O(1)

- **Space Complexity**: O(n)
  - Hash map can store up to n elements in worst case

## Example Walkthrough

```
nums = [2, 7, 11, 15], target = 9

Step 1: i=0, nums[0]=2
  complement = 9 - 2 = 7
  map is empty, so add {2: 0}

Step 2: i=1, nums[1]=7
  complement = 9 - 7 = 2
  2 exists in map at index 0!
  Return [0, 1]
```
