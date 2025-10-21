/*
 * Problem: Climbing the Leaderboard
 * Link: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
 * Difficulty: Medium
 * Description: Determine Alice's rank on a leaderboard after each level she completes
 */

#include <stdio.h>
#include <stdlib.h>

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* result = (int*)malloc(player_count * sizeof(int));
    *result_count = player_count;
    
    // Remove duplicates and get unique ranks
    int unique[ranked_count];
    int unique_count = 0;
    unique[0] = ranked[0];
    unique_count = 1;
    
    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != ranked[i-1]) {
            unique[unique_count++] = ranked[i];
        }
    }
    
    int j = unique_count - 1;
    
    for (int i = 0; i < player_count; i++) {
        while (j >= 0 && player[i] >= unique[j]) {
            j--;
        }
        result[i] = j + 2;
    }
    
    return result;
}

int main() {
    int ranked_count;
    scanf("%d", &ranked_count);
    
    int* ranked = (int*)malloc(ranked_count * sizeof(int));
    for (int i = 0; i < ranked_count; i++) {
        scanf("%d", &ranked[i]);
    }
    
    int player_count;
    scanf("%d", &player_count);
    
    int* player = (int*)malloc(player_count * sizeof(int));
    for (int i = 0; i < player_count; i++) {
        scanf("%d", &player[i]);
    }
    
    int result_count;
    int* result = climbingLeaderboard(ranked_count, ranked, player_count, player, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }
    
    free(ranked);
    free(player);
    free(result);
    
    return 0;
}
