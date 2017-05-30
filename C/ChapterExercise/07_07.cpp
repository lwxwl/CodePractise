#include <stdio.h>
#include <string.h>
#define CITYNUM 10

int main() {
    int num;
    char city[CITYNUM][20];
    char str[80];

    num = 0;
    for (int i = 0; i < CITYNUM; i++) {
        printf("input the name of the %dth city: ", i + 1);
        gets(str);
        if (str[0] == 0) {
            break;
        }
        if (strlen(str) > 19) {
            i--;
            continue;
        }
        strcpy(city[i], str);
        num++;
    }
    for (int i = 0; i < num - 1; i++) {
        k = i;
        for (int j = i + 1; j < num; j++) {
            if (stricmp(city[k], city[j]) > 0) {
                k = j;
            }
        }
        if (k != i) {
            strcpy(str, city[i]);
            strcpy(city[i], city[k]);
            strcpy(city[k], str);
        }
    }
    for (int i = 0; i < num; i++) {
        printf("%s ", city[i]);
    }
    printf("\n");
    return 0;
}

