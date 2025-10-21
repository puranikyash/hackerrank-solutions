#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b) {
    int maxSpent = -1;
    
    for (int i = 0; i < keyboards_count; i++) {
        for (int j = 0; j < drives_count; j++) {
            int total = keyboards[i] + drives[j];
            
            if (total <= b && total > maxSpent) {
                maxSpent = total;
            }
        }
    }
    
    return maxSpent;
}

int main() {
    int b, n, m;
    scanf("%d %d %d", &b, &n, &m);
    
    int* keyboards = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &keyboards[i]);
    }
    
    int* drives = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &drives[i]);
    }
    
    int moneySpent = getMoneySpent(n, keyboards, m, drives, b);
    printf("%d\n", moneySpent);
    
    free(keyboards);
    free(drives);
    
    return 0;
}
