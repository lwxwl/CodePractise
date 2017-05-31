#include <stdio.h>

void add(char s1[], char s2[], char s3[]);

int main() {
    char str1[40], str2[40], str3[80];
    scanf("%s %s", str1, str2);
    add(str1, str2, str3);
    printf("%s", str3);
}

void add(char s1[], char s2[], char s3[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        s3[i] = s1[i];
    }
    for (j = 0; s2[j] != '\0'; j++) {
        s3[i + j] = s2[j];
    }
    s3[i + j] = '\0';
}

