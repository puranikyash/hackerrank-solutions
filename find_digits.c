/*
 * Problem: Find Digits
 * Link: https://www.hackerrank.com/challenges/find-digits/problem
 * Difficulty: Easy
 * Description: Find how many digits of a number divide that number evenly
 */

#include <stdio.h>

int findDigits(int n) {
    int count = 0;
    int original = n;
    
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && original % digit == 0) {
            count++;
        }
        n /= 10;
    }
    
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        int result = findDigits(n);
        printf("%d\n", result);
    }
    
    return 0;
}
