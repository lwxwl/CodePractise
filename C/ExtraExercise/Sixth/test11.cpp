// 已有变量定义和函数调用语句：int a=1,b=-5,c;c=fun(a,b);
// fun函数的作用是计算两个数之差的绝对值，并将差值返回调用函数，请编写fun函数
fun(int x, int y) {
    if (x >= y) {
        return x - y;
    } else {
        return y - x;
    }
}
