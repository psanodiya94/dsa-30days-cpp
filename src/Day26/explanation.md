# Day 26: Course Schedule - Explanation

## Approach: Topological Sort (Cycle Detection)

Use DFS or BFS to detect cycles in the directed graph. If there's a cycle, courses can't be completed.

## Algorithm (DFS with States)

1. Build adjacency list from prerequisites
2. Create state array: 0=unvisited, 1=visiting, 2=visited
3. For each course:
   - If unvisited, perform DFS
   - If cycle detected, return false
4. Return true

**DFS**:
- Mark as visiting (1)
- For each prerequisite:
  - If visiting (cycle detected): return false
  - If unvisited: DFS recursively
- Mark as visited (2)

## Intuition

**Graph representation**:
- Courses are nodes
- Prerequisites are directed edges
- `[a, b]` means edge from b → a (b must come before a)

**Cycle detection**:
- If there's a cycle, some courses depend on each other
- Impossible to complete all courses

**Three states**:
- Unvisited (0): not explored yet
- Visiting (1): currently in DFS path (gray node)
- Visited (2): completely explored (black node)

If we reach a "visiting" node, we found a back edge (cycle).

## Complexity Analysis

- **Time Complexity**: O(V + E)
  - V = numCourses, E = prerequisites
  - Visit each node and edge once

- **Space Complexity**: O(V + E)
  - Adjacency list + recursion stack

## Example Walkthrough

```
numCourses = 4
prerequisites = [[1,0], [2,1], [3,2]]

Graph: 0 → 1 → 2 → 3

DFS from 0:
  Mark 0 as visiting
  Visit 1:
    Mark 1 as visiting
    Visit 2:
      Mark 2 as visiting
      Visit 3:
        Mark 3 as visiting
        No prereqs, mark 3 as visited
      Mark 2 as visited
    Mark 1 as visited
  Mark 0 as visited

No cycles detected → true
```

```
prerequisites = [[1,0], [0,1]]

Graph: 0 ⇄ 1 (cycle!)

DFS from 0:
  Mark 0 as visiting
  Visit 1:
    Mark 1 as visiting
    Visit 0:
      0 is visiting! Cycle detected!

→ false
```
