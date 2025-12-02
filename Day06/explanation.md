# Day 06: Valid Anagram - Explanation

## Approach 1: Sorting

Sort both strings and compare if they're equal.

## Approach 2: Hash Map (Character Frequency)

Count frequency of each character in both strings and compare.

## Algorithm (Hash Map Approach)

1. If lengths differ, return false
2. Create frequency map for string `s`
3. Iterate through string `t`:
   - Decrement count for each character
   - If character not found or count becomes negative, return false
4. Return true

## Alternative: Array-based Frequency

Since we only have lowercase English letters (26 characters), we can use an array of size 26 instead of a hash map.

## Intuition

Two strings are anagrams if:
- They have the same length
- They contain the same characters with the same frequencies

Using a frequency counter is more efficient than sorting for large strings.

## Complexity Analysis

### Hash Map / Array Approach:
- **Time Complexity**: O(n)
  - One pass through each string
  - n is the length of the strings

- **Space Complexity**: O(1)
  - Array of size 26 (constant space)
  - Or O(k) where k is the character set size

### Sorting Approach:
- **Time Complexity**: O(n log n)
  - Sorting dominates

- **Space Complexity**: O(1) or O(n)
  - Depends on sorting algorithm

## Example Walkthrough

```
s = "anagram", t = "nagaram"

Frequency counting:
s: a=3, n=1, g=1, r=1, m=1
t: n=1, a=3, g=1, r=1, m=1

Both have same frequencies → true
```

```
s = "rat", t = "car"

Frequency counting:
s: r=1, a=1, t=1
t: c=1, a=1, r=1

't' is in s but not in t
'c' is in t but not in s
→ false
```
