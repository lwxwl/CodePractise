// 已有变量定义和函数调用语句：int x=57; isprime(x);
// 函数isprime()用来判断一个整型数是否为素数，若是素数，函数返回1，否则返回0。
// 请编写isprime函数。
isprime(int a) {
    int b, i;
    b = sqrt(a);
    for (i = b; i > 1; i--) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;

}
