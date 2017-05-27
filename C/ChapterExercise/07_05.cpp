#include <stdio.h>
#define NUM_std 5
#define NUM_course 4

int main() {
    float score[NUM_std + 1][NUM_course + 1] = {0};

    for (int i = 0; i < NUM_std; i++) {
        for (int j = 0; j < NUM_course; j++) {
            printf("input the mark of %th course of %dth student: ", j + 1, i + 1);
            scanf("%f", &score[i][j]);
        }

        for (int i = 0; i < NUM_std; i++) {
            for (int j = 0; j < NUM_course; j++) {
                score[i][NUM_course] += score[i][j];
                score[NUM_std][j] += score[i][j];
            }
            score[i][NUM_course] /= NUM_course;
        }
        for (int j = 0; j < NUM_course; j++) {
            score[NUM_std][j] /= NUM_std;
        }
        printf("NO.      C1      C2      C3      C4      AVER\n");
        for (int i = 0; i < NUM_std; i++) {
            printf("STU%d\t", i +1);
            for (int j = 0; j < NUM_course + 1; j++) {
                printf("%6.1f\t", score[i][j]);
            }
            printf("\n");
        }
    }

}
