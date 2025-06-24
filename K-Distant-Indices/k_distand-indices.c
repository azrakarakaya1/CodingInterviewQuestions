#include <stdlib.h>
#include <stdio.h>

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {

    int count = 0;

    int *dp = (int *)calloc(numsSize, sizeof(int));
    if (!dp) return (NULL);

    // mark all k-distant indices in dp
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            int start = ((i - k) <= 0) ? 0 : i - k;
            int end =  ((i + k) >= numsSize - 1) ? numsSize - 1 : i + k;
            for(int j = start; j <= end; j++) {
                if (dp[j] == 0) {
                    dp[j] = 1;
                    count++;
                }
            }
        }
    }

    //allocate memory for resulting array
    int *k_distant = (int *)calloc(count, sizeof(int));
    if (!k_distant) {
        free(dp);
        return (NULL);
    }

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (dp[i]) k_distant[index++] = i;
    }

    free(dp);
    *returnSize = count;
    return (k_distant);
}

// Main function
int main() {
    int nums[] = {3, 4, 9, 1, 3, 9, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int key = 9;
    int k = 1;
    int returnSize = 0;

    int* result = findKDistantIndices(nums, numsSize, key, k, &returnSize);

    if (result == NULL) {
        printf("Memory allocation failed or no result.\n");
        return 1;
    }

    printf("K-Distant indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}