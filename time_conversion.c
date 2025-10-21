#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* timeConversion(char* s) {
    char* result = malloc(9 * sizeof(char));
    int hour, min, sec;
    char period[3];
    
    // Parse the time string
    sscanf(s, "%d:%d:%d%s", &hour, &min, &sec, period);
    
    // Convert based on AM/PM
    if (strcmp(period, "AM") == 0) {
        if (hour == 12) {
            hour = 0;  // 12 AM is 00 hours
        }
    } else {  // PM
        if (hour != 12) {
            hour += 12;  // Add 12 for PM (except 12 PM)
        }
    }
    
    // Format the result
    sprintf(result, "%02d:%02d:%02d", hour, min, sec);
    return result;
}

int main() {
    char s[11];
    scanf("%s", s);
    
    char* result = timeConversion(s);
    printf("%s\n", result);
    
    free(result);
    return 0;
}
