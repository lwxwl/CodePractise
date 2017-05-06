// 将两个字符串连接起来(不用strcat)。
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char str1[80], str2[40];
    int i = 0, j = 0;
    printf("Please input string1: ");
    scanf("%s", str1);
    printf("Please input string2: ");
    scanf("%s", str2);

    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
        str1[i] = '\0';
    }

    printf("The string is: %s", str1);
    getch();
}