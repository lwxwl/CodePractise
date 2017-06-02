#include <stdio.h>
#include <stdlib.h>

enum SEX {
    male, female
};

struct Student_Info {
    char no[9];
    char name[20];
    enum SEX sex;
    unsigned int age;
    unsigned int classno;
    float grade;
};
typedef struct Student_Info STUDENT;

STUDENT *GetStuInfo(int i);
void SortStuInfo(STUDENT **pstu, int num);
void FreeMemory(STUDENT **pstu, int num);

int main() {
    STUDENT **pstu;
    int i, num;

    printf("input the number of the students: ");
    scanf("%d", &num);
    if (num <= 0) {
        return NULL;
    }
    pstu = (STUDENT **)malloc(num * sizeof(STUDENT *));
    if (pstu == NULL) {
        printf("no enough memory!\n");
        return NULL;
    }
    for (int i = 0; i < num; i++) {
        pstu[i] = GetStuInfo(i);
        if (pstu[i] == NULL) {
            printf("no enough memory!\n");
            FreeMemory(pstu, i);
            return NULL;
        }
    }
    SortStuInfo(pstu, num);
    printf("\n============== sort result ============\n");
    for (int i = 0; i < num; i++) {
        printf("%12s%20s%9s%5d%5d%8.1f\n",
               pstu[i]->no, pstu[i]->name,
               (pstu[i]->sex == 'M') ? male : female, pstu[i]->age,
               pstu[i]->classno, pstu[i]->grade);
    }
    FreeMemory(pstu, num);
}

STUDENT *GetStuInfo(int i) {
    STUDENT *p;
    char sex;

    p = (STUDENT *) malloc(sizeof(STUDENT));
    if (p == NULL) {
        return NULL;
    }
    printf("\n==== input %dth student's information ====\n", i + 1);
    printf("no: ");
    scanf("%s", p->no);
    printf("name: ");
    scanf("%s", p->name);
    fflush(stdin);
    while (1) {
        printf("sex(M, F): ");
        scanf("%c", &sex);
        if (sex == 'F' || sex == 'M') {
            break;
        }
        fflush(stdin);
    }
    p->sex = (sex == 'M') ? male : female;
    printf("age: ");
    scanf("%d", &p->age);
    printf("classno: ");
    scanf("%d", &p->classno);
    printf("grade: ");
    scanf("%d", &p->grade);
    return p;
}

void SortStuInfo(STUDENT **pstu, int num) {
    STUDENT *p;
    int i, j, k;
    for (i = 0; i < num - 1; i++) {
        k = i;
        for (j = i + 1; j < num; j++) {
            if (pstu[j]->grade > pstu[k]->grade) {
                k = j;
            }
        }
        if (k != i) {
            p = pstu[i];
            pstu[i] = pstu[k];
            pstu[k] = p;
        }
    }
}

void FreeMemory(STUDENT **pstu, int num) {
    for (int i = 0; i < num; i++) {
        free(pstu[i]);
    }
    free(pstu);
}
