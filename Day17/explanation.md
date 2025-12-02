# Day 17: Valid Parentheses - Explanation

## Approach: Stack

Use a stack to track opening brackets and match with closing brackets.

## Algorithm

1. Create an empty stack
2. For each character in the string:
   - If it's an opening bracket `(`, `{`, `[`:
     - Push to stack
   - If it's a closing bracket `)`, `}`, `]`:
     - If stack is empty: return false (no matching opening)
     - If stack top doesn't match: return false
     - Otherwise: pop from stack
3. Return true if stack is empty (all matched), false otherwise

## Intuition

**Why stack?**
- Brackets must be closed in reverse order of opening (LIFO)
- Most recent opening bracket should be closed first
- Stack naturally handles this "last opened, first closed" pattern

**Matching brackets**:
- `(` matches with `)`
- `{` matches with `}`
- `[` matches with `]`

**Valid conditions**:
- Every opening has a corresponding closing
- Closing happens in correct order
- No extra opening or closing brackets

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through the string
  - Stack operations are O(1)

- **Space Complexity**: O(n)
  - Stack can hold up to n/2 opening brackets in worst case

## Example Walkthrough

```
s = "([{}])"

Step 1: '(' → push to stack
  stack = ['(']

Step 2: '[' → push to stack
  stack = ['(', '[']

Step 3: '{' → push to stack
  stack = ['(', '[', '{']

Step 4: '}' → matches '{', pop
  stack = ['(', '[']

Step 5: ']' → matches '[', pop
  stack = ['(']

Step 6: ')' → matches '(', pop
  stack = []

Stack is empty → valid!
```

```
s = "([)]"

Step 1-3: push '(', '[', '{'
  stack = ['(', '[']

Step 4: ')' → top is '[', doesn't match!
  return false
```
