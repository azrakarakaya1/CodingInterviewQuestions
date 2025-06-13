#include <stdio.h>

// Input matrix representing land: 1 = good, 0 = bad
int A[6][5] = {
    {0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};

#define ROW 6
#define COL 5

// Finds minimum of 3 integers
int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

// Time complexity: O(ROW * COL)    -> Each cell is visited once, and each min() is a constant-time operation.
int largestSquare(int A[ROW][COL]) {

    int dp[ROW][COL];       // DP table stores size of largest square ending at (i, j)
    int maxCount = 0;       // number of 1s in a side of current largest square

    // Fill dp table
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            
            // For first row or first column, square size is same as input cell
            if (i == 0 || j == 0)
                dp[i][j] = A[i][j];
            // If cell is 1, check neighbours to determine largest possible square
            else if (A[i][j] == 1)
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            // If cell is 0, no square can end here
            else
                dp[i][j] = 0;

            // Update maxCount if we found a larger square
            if (dp[i][j] > maxCount)
                maxCount = dp[i][j];
        }
    }

    // Return the area of the largest square
    return maxCount * maxCount;
}

int main() {

    int area = largestSquare(A);

    printf("Largest square area is %d", area);

    return 0;
}