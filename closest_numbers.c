/*
 * Problem: Closest Numbers
 * Link: https://www.hackerrank.com/challenges/closest-numbers/problem
 * Difficulty: Easy
 * Description: Find pairs with minimum absolute difference in an array
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void closestNumbers(int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), compare);
    
    int min_diff = INT_MAX;
    
    for (int i = 0; i < arr_count - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    for (int i = 0; i < arr_count - 1; i++) {
        if (arr[i + 1] - arr[i] == min_diff) {
            printf("%d %d ", arr[i], arr[i + 1]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    closestNumbers(n, arr);
    
    free(arr);
    return 0;
}
