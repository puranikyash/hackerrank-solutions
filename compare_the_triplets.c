#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* result = malloc(2 * sizeof(int));
    *result_count = 2;
    result[0] = 0; // Alice's score
    result[1] = 0; // Bob's score
    
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            result[0]++;
        } else if (a[i] < b[i]) {
            result[1]++;
        }
    }
    
    return result;
}

int main() {
    int a[3], b[3];
    
    // Read Alice's scores
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    // Read Bob's scores
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    
    int result_count;
    int* result = compareTriplets(3, a, 3, b, &result_count);
    
    printf("%d %d\n", result[0], result[1]);
    
    free(result);
    return 0;
}
