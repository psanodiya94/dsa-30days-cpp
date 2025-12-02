# Day 09: Group Anagrams - Explanation

## Approach: Hash Map with Sorted String as Key

Use sorted version of each string as a key to group anagrams.

## Algorithm

1. Create a hash map: `map<string, vector<string>>`
2. For each string in the input:
   - Sort the string to get a key
   - Add the original string to the map using this key
3. Collect all groups from the map values

## Intuition

**Key insight**:
- All anagrams have the same characters
- When sorted, all anagrams produce the same string
- Use sorted string as a unique identifier (key) for each group

**Example**:
- "eat", "tea", "ate" all sort to "aet"
- "tan", "nat" both sort to "ant"
- "bat" sorts to "abt"

**Why this works**:
- Hash map groups strings with identical sorted forms
- Each group contains exactly the anagrams

## Alternative Approach: Character Count as Key

Instead of sorting, use character frequency as key:
- Count frequency of each character
- Create a unique key like "a1b1c1" or use array as key
- Time: O(n × k) where k is max string length

## Complexity Analysis

### Sorting Approach:
- **Time Complexity**: O(n × k log k)
  - n is number of strings
  - k is maximum length of a string
  - Sorting each string takes O(k log k)

- **Space Complexity**: O(n × k)
  - Storing all strings in hash map

## Example Walkthrough

```
strs = ["eat","tea","tan","ate","nat","bat"]

Process "eat":
  sorted: "aet"
  map["aet"] = ["eat"]

Process "tea":
  sorted: "aet"
  map["aet"] = ["eat", "tea"]

Process "tan":
  sorted: "ant"
  map["ant"] = ["tan"]

Process "ate":
  sorted: "aet"
  map["aet"] = ["eat", "tea", "ate"]

Process "nat":
  sorted: "ant"
  map["ant"] = ["tan", "nat"]

Process "bat":
  sorted: "abt"
  map["abt"] = ["bat"]

Result: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
```
