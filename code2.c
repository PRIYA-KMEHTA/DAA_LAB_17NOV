#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* Time Complexity

Merge Sort consistently has a time complexity of O(𝑛log⁡𝑛)
O(nlogn) in all cases (best, average, and worst). This is because it always divides the array into two halves and merges them in linear time.

Quick Sort has an average and best-case time complexity of 𝑂(𝑛log𝑛)
O(nlogn), but in the worst case (when the pivot is poorly chosen), it degrades to 𝑂(𝑛2)O(n2). This happens when the pivot splits the array into highly uneven parts.

Space Complexity

Merge Sort requires 𝑂(𝑛)
O(n) additional memory to store temporary arrays used during the merge process. This makes it less memory-efficient, particularly for large datasets.

Quick Sort is in-place and uses 𝑂(log𝑛)
O(logn) space for the recursion stack in the best case, but it can use 𝑂(𝑛)
O(n) space in the worst case due to deep recursion.

Stability

Merge Sort is stable, meaning it preserves the relative order of equal elements in the array.

Quick Sort is not stable by default, as it may swap equal elements arbitrarily during partitioning. However, it can be modified to become stable.

Divide and Conquer Strategy

Merge Sort divides the array into two equal halves regardless of the input, which ensures balanced and predictable behavior.

Quick Sort divides the array based on a pivot element. If the pivot is well-chosen (e.g., median), the partitions are balanced; otherwise, the partitions can become highly skewed.

Cache Efficiency

Merge Sort accesses memory in a more scattered fashion because it works on separate temporary arrays, making it less cache-friendly.

Quick Sort works on contiguous portions of the array, which improves cache performance and often makes it faster in practice.*/

