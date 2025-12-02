# Day 04: Product of Array Except Self - Explanation

## Approach: Prefix and Suffix Products

The key insight is to compute products from left and right separately.

For each position `i`:
- Product except self = (product of all elements to the left) × (product of all elements to the right)

## Algorithm

### Two-Pass Solution:

1. **First pass (left to right)**: Calculate prefix products
   - `result[i]` = product of all elements before index `i`

2. **Second pass (right to left)**: Calculate suffix products
   - Multiply `result[i]` by product of all elements after index `i`

### Implementation:
```
Pass 1 (Prefix):
result[0] = 1
result[1] = nums[0]
result[2] = nums[0] * nums[1]
result[3] = nums[0] * nums[1] * nums[2]

Pass 2 (Suffix):
suffix = 1
result[3] *= suffix (suffix = 1)
suffix *= nums[3]
result[2] *= suffix (suffix = nums[3])
suffix *= nums[2]
result[1] *= suffix (suffix = nums[3] * nums[2])
...
```

## Intuition

Think of it as:
```
For nums = [a, b, c, d]

result[0] = b * c * d
result[1] = a * c * d
result[2] = a * b * d
result[3] = a * b * c
```

Each result is the product of:
- Everything before it (prefix)
- Everything after it (suffix)

## Complexity Analysis

- **Time Complexity**: O(n)
  - Two passes through the array

- **Space Complexity**: O(1)
  - Only output array (which doesn't count)
  - One variable for suffix product

## Example Walkthrough

```
nums = [1, 2, 3, 4]

Pass 1 (Prefix Products):
result = [1, 1, 2, 6]
         [1, 1×1, 1×2, 1×2×3]

Pass 2 (Suffix Products):
suffix = 1
i=3: result[3] = 6 × 1 = 6,  suffix = 1 × 4 = 4
i=2: result[2] = 2 × 4 = 8,  suffix = 4 × 3 = 12
i=1: result[1] = 1 × 12 = 12, suffix = 12 × 2 = 24
i=0: result[0] = 1 × 24 = 24

Result: [24, 12, 8, 6]
```
