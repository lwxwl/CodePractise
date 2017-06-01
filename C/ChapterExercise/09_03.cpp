#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i;
    int max, min, sum;
    int *pscore;
    float ave;

    printf("input the number of students : ");
    scanf("%d", &num);
    if (num <= 0) {
        return 0;
    }

    pscore = (int *)malloc(num * sizeof(int));
    if (pscore == NULL) {
        printf("Inefficient memory available!");
        exit(0);
    }

    printf("input the scores of the students now: ");
    for (i = 0; i < num; i++) {
        scanf("%d", pscore + i);
    }

    max = pscore[0];
    min = pscore[0];
    sum = pscore[0];
    for (i = 1; i < num; i++) {
        if (pscore[i] > max) {
            max = pscore[i];
        }
        if (pscore[i] < min) {
            min = pscore[i];
        }
        sum += pscore[i];
        ave = (float) sum / num;
    }

    printf("---------------------------------------\n");
    printf("the highest score of the students is: %d\n", max);
    printf("the lowest score of the students is: %d\n", min);
    printf("the average score of the students is: %.1f\n", ave);

    free(pscore);
}
