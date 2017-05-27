#include <stdio.h>
#include <string.h>

int main() {

    char ch;
    int num[26], i;

    // 初始化数组num
    memset(num, 0, 26 * sizeof(int));
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            num[ch - 'A']++;
        }
    }

    for (i = 0; i < 26; i++) {
        // 控制一行输出9个结果
        if (i % 9 == 0) {
            printf("\n");
        }
        printf("%c(%d) ", 'A' + i, num[i]);
    }
    printf("\n");

    return 0;
}
