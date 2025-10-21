#include <stdio.h>
#include <string.h>

int countingValleys(int steps, char* path) {
    int altitude = 0;
    int valleys = 0;
    
    for (int i = 0; i < steps; i++) {
        int prevAltitude = altitude;
        
        if (path[i] == 'U') {
            altitude++;
        } else {
            altitude--;
        }
        
        // Count valley when we return to sea level from below
        if (prevAltitude < 0 && altitude == 0) {
            valleys++;
        }
    }
    
    return valleys;
}

int main() {
    int steps;
    char path[101];
    
    scanf("%d", &steps);
    scanf("%s", path);
    
    int result = countingValleys(steps, path);
    printf("%d\n", result);
    
    return 0;
}
