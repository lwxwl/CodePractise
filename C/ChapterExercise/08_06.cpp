#include <stdio.h>

int dif(int x, int y, int z);
int max(int x, int y, int z);
int min(int x, int y, int z);

int main() {
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    d = dif(a, b, c);
    printf("MAX - MIN = %d\n", d);
}




int dif(int x, int y, int z) {
    return (max(x, y, z) - min(x, y, z));
}

int max(int x, int y, int z) {
    int temp;
    temp = x > y ? x : y;
    return temp > z ? temp : z;
}

int min(int x, int y, int z) {
    int temp;
    temp = x < y ? x : y;
    return temp < z ? temp : z;
}

