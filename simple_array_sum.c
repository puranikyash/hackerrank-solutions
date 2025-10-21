#include <stdio.h>
#include <stdlib.h>

int simpleArraySum(int ar_count, int* ar) {
    int sum = 0;
    for (int i = 0; i < ar_count; i++) {
        sum += ar[i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* ar = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    
    int result = simpleArraySum(n, ar);
    printf("%d\n", result);
    
    free(ar);
    return 0;
}
