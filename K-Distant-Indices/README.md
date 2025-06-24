# LeetCode 2200 – Find All K-Distant Indices in an Array

## Problem Description

For the given a **0-indexed** integer array `nums`, an integer `key`, and an integer `k`.

A **k-distant index** is an index `i` in the array such that there exists at least one index `j` with:

|i - j| <= k and nums[j] == key


Return a sorted list of all `k`-distant indices in increasing order.

### Example

**Input:**

nums = [3,4,9,1,3,9,5], key = 9, k = 1

**Output:**

[1, 2, 3, 4, 5, 6]


## Approach

We iterate through the array to find all occurrences of key. For each index i, we mark all indices from i - k to i + k (while checking bounds) as valid k-distant indices.

We use a temporary array dp[] of size numsSize to mark each valid index only once and count them. After marking, we collect all the marked indices in a result array which will be returned.


## Dynamic Programming Concept

Although this solution does not use classic DP with overlapping subproblems and memoization, it uses dynamic programming principles through a temporary dp[] array that tracks state — whether each index is part of the result or not.

he array acts like a state cache:

- dp[i] = 1 means index i is k-distant from some key
- Duplicate computation is avoided by checking if (dp[j] == 0) before marking and counting

This use of a state array to store decisions and avoid recomputation is important in DP strategies.


## Algorithm Analysis

| Metric            | Value                                                  |
|-------------------|--------------------------------------------------------|
| **Time Complexity**| `O(n * k)` worst case, where `n` is `numsSize`. In most cases, it’s closer to `O(n)` |
| **Space Complexity**| `O(n)` for auxiliary `dp[]` and the result array      |

- Loop through each element once to find occurrences of the `key`
- For each `key` index, scan up to `2k + 1` elements around it
- Use linear extra space for marking valid indices and storing results


---

## Conclusion

This solution is efficient, easy to implement, and memory-safe. It uses an auxiliary state array inspired by dynamic programming to track valid indices and avoids duplicate work through smart marking.

It maintains LeetCode constraints and runs within time/space limits even at maximum input size (nums.length <= 1000).