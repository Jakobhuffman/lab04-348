#include <stdio.h>

/** 
 *  TD + saftey = 8
    TD + FG = 7
    TD = 6
    FG = 3
    saftey = 2
*/

void score_combos(int score, int td_s, int td_fg, int td, int fg, int saftey) {
    int total_score = td_s * 8 + td_fg * 7 + td * 6 + fg * 3 + saftey * 2;

   
    if (total_score == score) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_s, td_fg, td, fg, saftey);
        return;
    }

    
    if (total_score > score) {
        return;
    }

    score_combos(score, td_s + 1, td_fg, td, fg, saftey); 
    score_combos(score, td_s, td_fg + 1, td, fg, saftey); 
    score_combos(score, td_s, td_fg, td + 1, fg, saftey); 
    score_combos(score, td_s, td_fg, td, fg + 1, saftey); 
    score_combos(score, td_s, td_fg, td, fg, saftey + 1);
}

int main() {
    int user_score;

    while (1) {
        printf("Enter a NFL Score -> ");
        scanf("%d", &user_score);

        
        if (user_score <= 1) {
            break;
        } else {
            printf("All combinations:\n");
            score_combos(user_score, 0, 0, 0, 0, 0);
        }
    }

    return 0;
}