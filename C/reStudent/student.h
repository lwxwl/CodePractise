//
// Created by 夏玮蔚 on 2017/6/3.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum SEX{
    male, female
};

struct Level{
    int Excellent;
    int Fine;
    int Medium;
    int Pass;
    int Failed;
};
struct Student_Info{
    char no[9];
    char name[20];
    enum SEX sex;
    int age;
    int classno;
    float Math, C_Language, English;
    float sum, ave;
};
typedef struct Student_Info STUDENT;

void SystemSet();
int ScanfSet();
void UserInterface();
void returnUserFace();
void readDate(STUDENT *student, int *num);
void ComputeScoreBySubject(STUDENT *student, int *num);
void ComputeScoreByStudent(STUDENT *student, int *num);
void SortScore(STUDENT *student, int *num);
int orderDecrease(const void *a, const void *b);
int orderIncrease(const void *a, const void *b);
int orderNo(const void *a, const void *b);
int orderName(const void *a, const void *b);
void PrintAfterSort(STUDENT *student, int *num);
void SearchByNo(STUDENT *student, int *num);
void SearchByName(STUDENT *student, int *num);
void GetSum(STUDENT *student, int *num);
void WriteFile(STUDENT *student, int *num);
void ReadFile(STUDENT *student, int *num);


// 系统设置
void SystemSet() {
    system("title  学生管理系统");
}
// 读取选项
int ScanfSet() {
    int n;
    scanf("%d", &n);
    return n;
}
// 用户界面
void UserInterface() {
    printf("1. 录入数据\n");
    printf("2. 统计数据（按学生）\n");
    printf("3. 统计数据（按科目）\n");
    printf("4. 统计数据（按百分比）\n");
    printf("5. 结果排序（总分从高到低）\n");
    printf("6. 结果排序（总分从低到高）\n");
    printf("7. 结果排序（学号顺序）\n");
    printf("8. 结果排序（姓名的字典顺序）\n");
    printf("9. 查找数据（按学号）\n");
    printf("10. 查找数据（按姓名）\n");
    printf("11. 显示数据\n");
    printf("12. 写入文件\n");
    printf("13. 读取文件\n");
    printf("请输入您的选择： \n");
}
// 返回用户界面
void returnUserFace() {
    while(getchar() != '\n');
    system("pause");  // 按任意键继续
    system("cls");    // 清除屏幕
    UserInterface();
}
// 读取数据
void readDate(STUDENT *student, int *num) {
    char sex;
    printf("请输入学生的数目: \n");
    scanf("%d", num);

    for (int i = 0; i < *num; i++) {
        printf("\n==请输入第%d位学生的学号== \n", i + 1);
        scanf("%s", student[i].no);
        fflush(stdin);
        printf("\n==请输入学号为%s的学生信息== \n", student[i].no);
        printf("姓名： ");
        scanf("%s", student[i].name);
        fflush(stdin);
        while (1) {
            printf("性别(M,F): ");
            scanf("%c", &sex);
            fflush(stdin);
            if (sex == 'M' || sex == 'F') {
                break;
            }
        }
        student[i].sex = (sex == 'M') ? male : female;
        printf("年龄: ");
        scanf("%d", &student[i].age);
        fflush(stdin);
        printf("班级: ");
        scanf("%d", &student[i].classno);
        fflush(stdin);
        printf("数学: ");
        scanf("%f", &student[i].Math);
        fflush(stdin);
        printf("英语: ");
        scanf("%f", &student[i].English);
        fflush(stdin);
        printf("C语言: ");
        scanf("%f", &student[i].C_Language);
        fflush(stdin);
    }
    returnUserFace();
}

void ComputeScoreBySubject(STUDENT *student, int *num) {
    float max, min;
    float sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < *num; i++) {
        sum1 += student[i].Math;
        sum2 += student[i].English;
        sum3 += student[i].C_Language;
    }
    max = (sum1 > sum2) ? sum1 : sum2;
    max = (max > sum3) ? max : sum3;
    min = (sum1 < sum2) ? sum1 : sum2;
    min = (min < sum3) ? min : sum3;
    printf("数学的总分是: %-8.2f;  平均分是: %-8.2f\n", 1.0 * sum1, 1.0 * sum1 / (*num));
    printf("英语的总分是: %-8.2f;  平均分是: %-8.2f\n", 1.0 * sum2, 1.0 * sum2 / (*num));
    printf("C语言的总分是: %-8.2f; 平均分是: %-8.2f\n", 1.0 * sum3, 1.0 * sum3 / (*num));
    printf("三门课程中平均分最高为: %-8.2f 最低为: %-8.2f\n", 1.0 * max / (*num), 1.0 * min / (*num));
    returnUserFace();
}

void ComputeScoreByStudent(STUDENT *student, int *num) {
    float max = 0, min = 301;
    for (int i = 0; i < *num; i++) {
        float sum = 0;
        sum = student[i].Math + student[i].English + student[i].C_Language;
        student[i].sum = sum;
        printf("%-12s%-10s ", student[i].no, student[i].name);
        printf("总分: %-8.2f 平均分: %-8.2f\n", 1.0 * sum, 1.0 * sum / 3);
    }
    for (int n = 0; n < *num; n++) {
        if (student[n].sum > max) {
            max = student[n].sum;
        } else if (student[n].sum < min) {
            min = student[n].sum;
        }
    }
    printf("总分最高为: %-8.2f 最低为: %-8.2f\n", max, min);
    return UserInterface();
}
// 存疑
void SortScore(STUDENT *student, int *num) {
    struct Level subject[3] = {0};
    for (int i = 0; i < *num; i++) {
        if (student[i].Math >= 90 && student[i].Math <= 100) {
            subject[0].Excellent++;
        } else if (student[i].Math >= 80 && student[i].Math < 90) {
            subject[0].Fine++;
        } else if (student[i].Math >= 70 && student[i].Math < 80) {
            subject[0].Medium++;
        } else if (student[i].Math >= 60 && student[i].Math < 70) {
            subject[0].Pass++;
        } else {
            subject[0].Failed++;
        }

        if (student[i].English >= 90 && student[i].English <= 100) {
            subject[1].Excellent++;
        } else if (student[i].English >= 80 && student[i].English < 90) {
            subject[1].Fine++;
        } else if (student[i].English >= 70 && student[i].English < 80) {
            subject[1].Medium++;
        } else if (student[i].English >= 60 && student[i].English < 70) {
            subject[1].Pass++;
        } else {
            subject[1].Failed;
        }

        if (student[i].C_Language >= 90 && student[i].C_Language <= 100) {
            subject[2].Excellent++;
        } else if (student[i].C_Language >= 80 && student[i].C_Language < 90) {
            subject[2].Fine++;
        } else if (student[i].C_Language >= 70 && student[i].C_Language < 80) {
            subject[2].Medium++;
        } else if (student[i].C_Language >= 60 && student[i].C_Language < 70) {
            subject[2].Pass++;
        } else {
            subject[2].Failed;
        }
    }

    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("数学: \n");
                break;
            case 1:
                printf("英语: \n");
                break;
            case 2:
                printf("C语言: \n");
                break;
            default:
                break;
        }
        printf("优秀(90-100) %2d %-5.2f%%\n", subject[i].Excellent, 1.0 * subject[i].Excellent / (*num) * 100);
        printf("良好(80-89)  %2d %-5.2f%%\n", subject[i].Fine, 1.0 * subject[i].Fine / (*num) * 100);
        printf("中等(70-79)  %2d %-5.2f%%\n", subject[i].Medium, 1.0 * subject[i].Medium / (*num) * 100);
        printf("及格(60-69)  %2d %-5.2f%%\n", subject[i].Pass, 1.0 * subject[i].Pass / (*num) * 100);
        printf("不及格(0-59) %2d %-5.2f%%\n", subject[i].Failed, 1.0 * subject[i].Failed / (*num) * 100);
    }
    returnUserFace();
}

int orderDecrease(const void *a, const void *b) {
    STUDENT *p1 = (STUDENT *) a;
    STUDENT *p2 = (STUDENT *) b;
    return (p1->sum) - (p2->sum);
}

int orderIncrease(const void *a, const void *b) {
    STUDENT *p1 = (STUDENT *) a;
    STUDENT *p2 = (STUDENT *) b;
    return (p2->sum) - (p1->sum);
}

int orderNo(const void *a, const void *b) {
    STUDENT *p1 = (STUDENT *) a;
    STUDENT *p2 = (STUDENT *) b;
    return (p2->no) - (p1->no);
}

int orderName(const void *a, const void *b) {
    STUDENT *p1 = (STUDENT *) a;
    STUDENT *p2 = (STUDENT *) b;
    return strcmp((p1->name), (p2->name));
}

// 打印每门成绩以及总分、平均分
void PrintAfterSort(STUDENT *student, int *num) {
    for (int i = 0; i < *num; i++) {
        printf("%-12s%-10s 分数: ", student[i].no, student[i].name);
        printf("数学: %-8.2f", student[i].Math);
        printf("英语: %-8.2f", student[i].English);
        printf("C语言: %-8.2f", student[i].C_Language);
        printf("总分: %-8.2f 平均分: %-8.2f", student[i].sum, student[i].sum / 3);
        printf("\n");
    }
    returnUserFace();
}

void SearchByNo(STUDENT *student, int *num) {
    int flag;
    char c, no[10];
    E:
    printf("请输入学号\n");
    flag = 0;
    scanf("%s", no);
    for (int i = 0; i < *num; i++) {
        if (strcmp(student[i].no, no) == 0) {
            printf("%-12s%-10s ", student[i].no, student[i].name);
            printf("数学: %-8.2f", student[i].Math);
            printf("英语: %-8.2f", student[i].English);
            printf("C语言: %-8.2f", student[i].C_Language);
            flag = 1;
        }
    }
    if (flag == 1) {
        putchar(10);
    } else {
        printf("没找到该学生\n");
    }
    getchar();

    E1:
    printf("输入\"n\"结束或者输入\"y\"继续\n");
    scanf("%c", &c);
    if (c == 'y') {
        goto E;
    } else if (c == 'n') {
        returnUserFace();
    } else {
        while (getchar() != '\n');
        goto E1;
    }
}

void SearchByName(STUDENT *student, int *num) {
    int flag;
    char c, name[20];
    E:
    printf("请输入学生的名字\n");
    flag = 0;
    scanf("%s", name);
    for (int i = 0; i < *num; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("%-12s%-10s", student[i].no, student[i].name);
            printf("数学: %-8.2f", student[i].Math);
            printf("英语: %-8.2f", student[i].English);
            printf("C语言: %-8.2f", student[i].C_Language);
            flag = 1;
        }
    }
    if (flag == 1) {
        putchar(10);
    } else {
        printf("没找该到学生\n");
    }
    getchar();

    E1:
    printf("输入\"n\"结束或者输入\"y\"继续\n");
    scanf("%c", &c);
    if (c == 'y') {
        goto E;
    } else if (c == 'n') {
        returnUserFace();
    } else {
        while (getchar() != '\n');
        goto E1;
    }
}

// 计算每个学生的总分
void GetSum(STUDENT *student, int *num) {
    float sum;
    for (int i = 0; i < *num; i++) {
        sum = 0;
        sum = student[i].Math + student[i].English + student[i].C_Language;
        student[i].sum = sum;
    }
}

void WriteFile(STUDENT *student, int *num) {
    FILE *p;
    if ((p = fopen("student.txt", "w")) == NULL) {
        printf("打开文件失败\n");
        exit(0);
    } else {
        fprintf(p, "%d\n", *num);
        for (int i = 0; i < *num; i++) {
            fprintf(p ,"%-12s%-10s ", student[i].no, student[i].name);
            fprintf(p, "%-8.2f", student[i].Math);
            fprintf(p, "%-8.2f", student[i].English);
            fprintf(p, "%-8.2f", student[i].C_Language);
            fprintf(p, " %-8.2f %-8.2f", student[i].sum, student[i].sum / 3);
            fprintf(p,"\n");
        }
    }
    fclose(p);
    printf("写入成功\n");
    returnUserFace();
}

void ReadFile(STUDENT *student, int *num) {
    FILE *p;
    if ((p = fopen("student.txt", "r")) == NULL) {
        printf("打开文件失败\n");
        exit(0);
    } else {
        fscanf(p, "%d", num);
        for (int i = 0; i < *num; i++) {
            fscanf(p, "%s%s", student[i].no, student[i].name);
            fscanf(p, "%f", &student[i].Math);
            fscanf(p, "%f", &student[i].English);
            fscanf(p, "%f", &student[i].C_Language);
            fscanf(p, "%f%f", &student[i].sum, &student[i].ave);
            fscanf(p,"\n");
        }
    }
    fclose(p);
}

#endif //UNTITLED_STUDENT_H



