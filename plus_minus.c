#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], i;
    float pos = 0, neg = 0, zero = 0;
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > 0) pos++;
        else if(arr[i] < 0) neg++;
        else zero++;
    }

    printf("%.6f\n", pos/n);
    printf("%.6f\n", neg/n);
    printf("%.6f\n", zero/n);

    return 0;
}
