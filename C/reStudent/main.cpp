#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXNUM	100

int main() {
    int num = 0;
    STUDENT student[MAXNUM];
    SystemSet();
    UserInterface();
    while (1) {
        switch (ScanfSet()) {
            case 0:
                exit(0);
            case 1:
                system("cls");
                readDate(student, &num);
                break;
            case 2:
                system("cls");
                ComputeScoreBySubject(student, &num);
                break;
            case 3:
                system("cls");
                ComputeScoreByStudent(student, &num);
                break;
            case 4:
                system("cls");
                SortScore(student, &num);
                break;
            case 5:
                system("cls");
                qsort(student, num, sizeof(STUDENT), orderDecrease);
                PrintAfterSort(student ,&num);
                break;
            case 6:
                system("cls");
                qsort(student, num, sizeof(STUDENT), orderIncrease);
                PrintAfterSort(student, &num);
                break;
            case 7:
                system("cls");
                qsort(student, num, sizeof(STUDENT), orderNo);
                PrintAfterSort(student, &num);
                break;
            case 8:
                system("cls");
                qsort(student, num, sizeof(STUDENT), orderName);
                PrintAfterSort(student, &num);
                break;
            case 9:
                system("cls");
                SearchByNo(student, &num);
                break;
            case 10:
                system("cls");
                SearchByName(student, &num);
                break;
            case 11:
                system("cls");
                GetSum(student, &num);
                PrintAfterSort(student, &num);
                break;
            case 12:
                system("cls");
                GetSum(student, &num);
                WriteFile(student, &num);
                break;
            case 13:
                system("cls");
                ReadFile(student, &num);
                GetSum(student, &num);
                PrintAfterSort(student, &num);
                break;
            default:
                system("cls");
                printf("Please input 0-13\n");
                returnUserFace();
                break;
        }
   }
}

