/*
 * Problem: Strong Password
 * Link: https://www.hackerrank.com/challenges/strong-password/problem
 * Difficulty: Easy
 * Description: Determine minimum characters needed to make a password strong
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int minimumNumber(int n, char* password) {
    int has_digit = 0;
    int has_lower = 0;
    int has_upper = 0;
    int has_special = 0;
    char special_chars[] = "!@#$%^&*()-+";
    
    for (int i = 0; i < n; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (strchr(special_chars, password[i]) != NULL) {
            has_special = 1;
        }
    }
    
    int missing = 0;
    if (!has_digit) missing++;
    if (!has_lower) missing++;
    if (!has_upper) missing++;
    if (!has_special) missing++;
    
    int needed = missing;
    if (n + needed < 6) {
        needed = 6 - n;
    }
    
    return needed;
}

int main() {
    int n;
    scanf("%d", &n);
    
    char password[101];
    scanf("%s", password);
    
    int result = minimumNumber(n, password);
    printf("%d\n", result);
    
    return 0;
}
