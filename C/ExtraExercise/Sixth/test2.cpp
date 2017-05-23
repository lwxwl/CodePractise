// 输入若干整数，其值均在1至4的范围内，用-1作为输入结束标志，请编写函数f用于统计每个整数的个数
#include <stdio.h>
#define M 50

main() {
    int a[M], c[5] = {0}, i, n, x;
    n = 0;
    printf("Enter 1 or 2 or 3 or 4, to end with -1\n");
    scanf("%d", &x);
    while (x != -1) {
        if (x >= 1 && x <= 4) {
            a[n] = x;
            n++;
        }
        scanf("%d", &x);
    }
    
    f(a,c,n);
    printf("Output the result:\n");
    
    for (i = 1; i <= 4; i++) {
        printf("%d:%d\n",i,c[i]);
    }
    printf("\n");
}

f(int a[],int c[],int n) {
    for (; n > 0; n--) {
        switch(a[n - 1]) {
        case 1:
                c[1] += 1;
                break;
        case 2:
                c[2] += 1;
                break;
        case 3:
                c[3] += 1;
                break;
        case 4:
                c[4] += 1;
                break;
        }
    }

}
