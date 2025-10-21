#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int n = arr_rows;
    int primarySum = 0;
    int secondarySum = 0;
    
    for (int i = 0; i < n; i++) {
        primarySum += arr[i][i];            
        secondarySum += arr[i][n - 1 - i];   
    }
    
    return abs(primarySum - secondarySum);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int** arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int result = diagonalDifference(n, n, arr);
    printf("%d\n", result);
    
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
