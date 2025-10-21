/*
 * Problem: Missing Numbers
 * Link: https://www.hackerrank.com/challenges/missing-numbers/problem
 * Difficulty: Easy
 * Description: Find numbers that are in list b but not in list a
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 10001

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void missingNumbers(int arr_count, int* arr, int brr_count, int* brr) {
    int freq_arr[MAX_VAL] = {0};
    int freq_brr[MAX_VAL] = {0};
    
    for (int i = 0; i < arr_count; i++) {
        freq_arr[arr[i]]++;
    }
    
    for (int i = 0; i < brr_count; i++) {
        freq_brr[brr[i]]++;
    }
    
    int result[MAX_VAL];
    int result_count = 0;
    
    for (int i = 0; i < MAX_VAL; i++) {
        if (freq_brr[i] > freq_arr[i]) {
            result[result_count++] = i;
        }
    }
    
    qsort(result, result_count, sizeof(int), compare);
    
    for (int i = 0; i < result_count; i++) {
        printf("%d ", result[i]);
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
    
    int m;
    scanf("%d", &m);
    
    int* brr = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &brr[i]);
    }
    
    missingNumbers(n, arr, m, brr);
    
    free(arr);
    free(brr);
    
    return 0;
}
