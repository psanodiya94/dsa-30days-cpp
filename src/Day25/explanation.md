# Day 25: Number of Islands - Explanation

## Approach: DFS or BFS

Visit each cell, and when we find land ('1'), perform DFS/BFS to mark the entire island, then increment counter.

## Algorithm (DFS)

1. Initialize `count = 0`
2. For each cell (i, j) in grid:
   - If cell is '1' (unvisited land):
     - Increment count
     - DFS to mark all connected land as visited
3. Return count

**DFS function**:
- Mark current cell as visited ('0' or use visited set)
- Recursively visit all 4 neighbors (up, down, left, right)

## Intuition

**Island definition**:
- Connected component of '1's
- Connected horizontally or vertically (not diagonally)

**Why DFS works**:
- When we find land, DFS explores entire island
- Mark visited to avoid counting same island multiple times
- Each DFS call handles one complete island

**Alternative: BFS**:
- Use queue instead of recursion
- Same idea: explore all connected land

## Complexity Analysis

- **Time Complexity**: O(m × n)
  - Visit each cell at most twice (once in loop, once in DFS)

- **Space Complexity**: O(m × n)
  - DFS recursion stack in worst case (entire grid is one island)

## Example Walkthrough

```
grid = [
  ["1","1","0"],
  ["1","0","0"],
  ["0","0","1"]
]

(0,0): Found '1', count=1
  DFS marks (0,0), (0,1), (1,0) as visited

(0,1): Already visited, skip
(0,2): '0', skip
(1,0): Already visited, skip
(1,1): '0', skip
(1,2): '0', skip
(2,0): '0', skip
(2,1): '0', skip
(2,2): Found '1', count=2
  DFS marks (2,2) as visited

Result: 2 islands
```
