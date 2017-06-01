#include <stdio.h>
#include <string.h>
#define N 20

int tag = 0;

void beep();
void GetNumberStr(char s[]);
void AddNumberStr(char a[], char b[], char c[]);
char AddChar(char ch1, char ch2);
void LeftTrim(char str[]);

int main() {
    char a[N + 1] = {0}, b[N + 1] = {0}, c[N + 2];

    printf("a = ");
    while (strlen(a) == 0) {
        GetNumberStr(a);
    }
    printf("\nb = ");
    while (strlen(b) == 0) {
        GetNumberStr(b);
    }

    AddNumberStr(a, b, c);
    printf("\na + b = %s \n", c);
}

void beep() {
    printf("\07");
}

void GetNumberStr(char s[]) {
    int i = 0;
    char ch;

    while (1) {
        ch = getchar();
        if (ch == '\r') {
            break;
        }
        if (ch == '\b') {
            if (i > 0) {
                printf("%c %c", ch, ch);
                i--;
            } else {
                beep();
            }
            continue;
        }
        if (ch < '0' || ch > '9') {
            beep();
            continue;
        }
        if (i < N) {
            printf("%c", ch);
            s[i++] = ch;
        } else {
            beep();
        }
    }
    s[i] = '\0';
}

void AddNumberStr(char a[], char b[], char c[]) {
    int i, j, k;

    memset(c, ' ', N + 2);
    i = strlen(a) - 1;
    j = strlen(b) - 1;
    k = N;
    while (i >= 0 && j >= 0) {
        c[k--] = AddChar(a[i--], b[i--]);
    }
    while (i >= 0) {
        c[k--] = AddChar(a[i--], '0');
    }
    while (j >= 0) {
        c[k--] = AddChar(b[i--], '0');
    }
    if (tag == 1) {
        c[k] = '1';
    }
    c[N + 1] = '\0';
    LeftTrim(c);
}

char AddChar(char ch1, char ch2) {
    char ch;

    ch = (ch1 - 0x30 + ch2 - 0x30) + tag;
    if (ch >= 10) {
        tag = 1;
        return ch - 10 + 0x30;
    } else {
        tag = 0;
        return ch + 0x30;
    }

}

void LeftTrim(char str[]) {
    int i;

    for (i = 0; str[i] == ' '; i++);
    strcpy(str, str + i);
}

