#include <stdio.h>
#define NUM 100

int main() {
    int n;
    float score[NUM];
    float min, max, ave, pass, percentPass;
    int numPass, numGreat;

    while (1) {
        printf("input the number of student(<=%d): ", NUM);
        scanf("%d", &n);
        if (n >= 0 && n <= NUM) {
            break;
        }
        printf("Wrong input! try again!\n");
    }

    ave = 0;
    for (int i = 0; i < n; i++) {
        printf("input the score of the %dth student: ", i + 1);
        scanf("%f", &score[i]);
        ave += score[i];
    }
    ave /= n;

    max = 0;
    min = 100;
    numPass = 0;
    numGreat = 0;
    for (int i = 0; i < n; i++) {
        max = score[i] > max ? score[i] : max;
        min = score[i] < min ? score[i] : min;
        if (score[i] >= 60) {
            numPass++;
        }
        if (score[i] >= ave) {
            numGreat++;
        }
    }

    percentPass = 1.0 * numPass / n;
    printf("====== total result ======\n");
    printf("the highest score is %.2f\n", max);
    printf("the lowest score is %.2f\n", min);
    printf("the average score is %.2f\n", ave);
    printf("the pass ratio is %.2f%%\n", percentPass);
    printf("the number of pass is %d\n", numPass);
    printf("the number of exceed average score is %d\n", numGreat);

    return 0;
}