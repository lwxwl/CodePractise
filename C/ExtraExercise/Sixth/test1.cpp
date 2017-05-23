// a是一个2×4的整型数组，且各元素均已赋值。
// 函数max_value可求出其中的最大元素max，并将此值返回主调函数。
// 今有函数调用语句max=max_value(a);请编写max_value函数。
max_value(int arr[2][4]) {
    int i, j, maxarr;
    maxarr = arr[0][0];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (arr[i][j] > maxarr) {
                maxarr = arr[i][j];
            }
        }
    }
    return (maxarr);
}
