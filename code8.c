#include <stdio.h>



void sumOfSubsets(int arr[], int n, int target, int currentSum, int index, int subset[], int subsetSize) {
    if (currentSum == target) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    if (currentSum > target || index >= n) {
        return;
    }

    subset[subsetSize] = arr[index];
    sumOfSubsets(arr, n, target, currentSum + arr[index], index + 1, subset, subsetSize + 1);

    sumOfSubsets(arr, n, target, currentSum, index + 1, subset, subsetSize);
}

int main() {
    int arr[] = {10, 7, 5, 18, 12, 20, 15}; // Example set
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 35;
    int subset[MAX];

    printf("Subsets that sum to %d:\n", target);
    sumOfSubsets(arr, n, target, 0, 0, subset, 0);

    return 0;
}
