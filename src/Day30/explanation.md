# Day 30: Number of 1 Bits - Explanation

## Approach 1: Loop and Check Each Bit

Check each of the 32 bits.

## Approach 2: Brian Kernighan's Algorithm (Optimal)

Flip the rightmost 1 bit repeatedly.

## Algorithm (Brian Kernighan)

```
count = 0
while n != 0:
    n = n & (n - 1)  // Flip rightmost 1 bit
    count++
return count
```

## Intuition

**Method 1: Check each bit**:
- Use `n & 1` to check if rightmost bit is 1
- Right shift `n >> 1` to check next bit
- Repeat 32 times

**Method 2: Brian Kernighan's trick**:
- `n & (n - 1)` flips the rightmost 1 bit to 0
- Loop only as many times as there are 1 bits
- More efficient when there are few 1 bits

**Why `n & (n - 1)` works**:
```
n     = 10110100
n-1   = 10110011
n&(n-1)=10110000  (rightmost 1 became 0)
```

## Complexity Analysis

### Method 1 (Check each bit):
- **Time Complexity**: O(32) = O(1)
  - Fixed 32 iterations

- **Space Complexity**: O(1)

### Method 2 (Brian Kernighan):
- **Time Complexity**: O(k) where k is number of 1 bits
  - Best case: O(1), Worst case: O(32) = O(1)

- **Space Complexity**: O(1)

## Example Walkthrough

```
n = 11 (binary: 1011)

Using Brian Kernighan's algorithm:

Iteration 1:
  n     = 1011
  n-1   = 1010
  n&(n-1)=1010
  count = 1

Iteration 2:
  n     = 1010
  n-1   = 1001
  n&(n-1)=1000
  count = 2

Iteration 3:
  n     = 1000
  n-1   = 0111
  n&(n-1)=0000
  count = 3

n = 0, stop
Result: 3 one bits
```

## Bit Manipulation Tricks Summary

Throughout this challenge, remember these bit operations:
- `n & 1`: Check if odd
- `n >> 1`: Divide by 2
- `n << 1`: Multiply by 2
- `n & (n-1)`: Remove rightmost 1 bit
- `n ^ n`: Always 0
- `n | (1 << i)`: Set ith bit
- `n & ~(1 << i)`: Clear ith bit
- `n ^ (1 << i)`: Toggle ith bit
