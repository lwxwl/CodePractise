// 已有变量定义和函数调用语句：int a,b; b=sum(a);函数sum()用以求 ，和数作为函数值返回。
// 若a的值为10，经函数sum的计算后，b的值是55。请编写sum函数。
sum(int n) {
    if (n = 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}
