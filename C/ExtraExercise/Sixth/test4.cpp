// 以下函数p的功能是用递归方法计算x的n阶勒让德多项式的值。已有调用语句p(n,x);请编写p函数。递归公式如下
float p(int n, int x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else {
        return ((2 * n - 1) * n * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
}
