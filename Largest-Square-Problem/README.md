# Largest Square of 1s in a Binary Matrix

**Question:**

A farmer wants to farm their land with the maximum area where good land is present.

- The land is represented as a matrix with 1s and Os, where 1s mean "good land" and Os mean "bad land."
- The farmer only wants to farm in a square of good land with the maximum area.

Please help the farmer to find the maximum area of the land they can farm in good land.

Example:
| A (6x5) |   |   |   |   |   |
|---------|---|---|---|---|---|
|         | 0 | 1 | 1 | 0 | 1 |
|         | 1 | 1 | 0 | 1 | 0 |
|         | 0 | 1 | 1 | 1 | 0 |
|         | 1 | 1 | 1 | 1 | 0 |
|         | 1 | 1 | 1 | 1 | 1 |
|         | 0 | 0 | 0 | 0 | 0 |


---

**Solution:**

One way to solve this problem is using brute force approach where we try all possible options to find the best solution to a problem.

- Simple to implement but often inefficient
- Time complexity is generally very high, for this problem: O(n^3 x m^3)

Those features makes this approach not ideal.

For the optimal solution we can use dynamic programming approach to efficiently find the largest square made up entirely of 1s in a 2D binary matrix.

The key idea is to build a helper matrix (dp) where each cell dp[i][j] represents the size (side length) of the largest square that ends at position (i, j) in the original matrix. If the cell A[i][j] is 1, then dp[i][j] is calculated as 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]). This works because a square can only be formed at a cell if all three neighboring cells (top, left, and top-left diagonal) can also form smaller squares. 

By filling this dp table, we keep track of the maximum square side found so far. At the end, we square this side length to get the largest possible area. This method is efficient and reduces the time complexity to O(n × m), making it much faster than the brute force approach for larger matrices.
