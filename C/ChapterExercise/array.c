#include <stdlib.h>

int **mallocmn(int m, int n) {
    int **p;
    p = (int **) malloc (m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        p[i] = (int *) malloc (n * sizeof(int));
    }
    return p;
}


// int **a = (int **) malloc(m * sizeof(int *));
// int *b = (int) malloc(m * n * sizeof(int));
// for (int i = 0; i < m; i++) {
//     a[i] = b + i * n;
// }