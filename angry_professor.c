/*
 * Problem: Angry Professor
 * Link: https://www.hackerrank.com/challenges/angry-professor/problem
 * Difficulty: Easy
 * Description: Determine if the class is cancelled based on student arrival times
 */

#include <stdio.h>
#include <string.h>

char* angryProfessor(int k, int a_count, int* a) {
    int on_time = 0;
    
    for (int i = 0; i < a_count; i++) {
        if (a[i] <= 0) {
            on_time++;
        }
    }
    
    if (on_time >= k) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        int a[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        
        char* result = angryProfessor(k, n, a);
        printf("%s\n", result);
    }
    
    return 0;
}
