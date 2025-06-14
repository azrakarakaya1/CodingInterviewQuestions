# First Recurring Character in a String

Given a string, identify the first character that appears more than once when scanning the string from left to right. 

If no character repeats, return the NULL character ('\0').

Example:

- Input: "acbbac"
- Output: 'b'

- Input: "abcdef"
- Output: '\0'

---

**Solution:**

First algroithm:

1. Initialize an empty array dp[] to store seen characters.
2. For each character in the input string:
- Check if it exists in dp[] using checkRecurrence().
- If yes, return it as the first recurring character.
- If no, add it to dp[].
3. If no character repeats, return '\0'.

The algorithm uses a linear scan of the input string and, for each character, checks if it has already been seen by scanning through a dynamic array (dp) of previously encountered characters. 

The time complexity is O(n²) in the worst case due to the nested loop behavior (checkRecurrence being called inside a loop), where n is the length of the input string. 

The space complexity is O(n) due to storing previously seen characters in the dp array.

While the algorithm is correct and works for small inputs, it is inefficient for large strings due to its quadratic time complexity. A more optimal solution would use a hash table (or an array of 256 booleans if limited to ASCII) to check for previously seen characters in constant time, reducing the overall time complexity to O(n) and maintaining O(n) space usage.


Second algorithm: Hash table approach

1. Create a boolean array seen[256], initialized to 0, to track ASCII characters.
2. Loop through the string one character at a time:
- If the character is already marked as seen (seen[c] == 1), return it as the first recurring character.
- Otherwise, mark it as seen (seen[c] = 1).
3. If no character repeats, return the null character '\0'.

Time & Space Complexity

* Time: O(n) — each character is checked once.
* Space: O(1) — fixed-size array for ASCII characters.