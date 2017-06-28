#include <iostream>
using namespace std;

// 函数模版
template <class T>
T **Make2DArray(int m, int n)
{
    T **dm;
    dm = new T *[m];
    for (int i = 0; i < m; i++) {
        dm[i] = new T[n];
        if (dm[i] == NULL)
            exit(0);
    }
    return dm;      // return (T **)dm;
}

template <class T>
void Delete2DArray(T **dm, int m, int n)
{
    for (int i = 0; i < m; i++) {
        delete[]dm[i];
    }
    delete[]dm;
}

// 计算两个矩阵的乘积
int main()
{
    int m, k, n;
    int **dm1, **dm2, **dm;
    cout << "input matrix size m, k, n: ";
    cin >> m >> k >> n;
    dm1 = Make2DArray<int>(m, k);
    dm2 = Make2DArray<int>(k, n);
    dm = Make2DArray<int>(m, n);
    cout << "input the first matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> dm1[i][j];
        }
    }
    cout << "input the second matrix: " << endl;for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dm2[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                dm[i][j] += dm1[i][l] * dm2[l][j];
            }
        }
    }
    cout << "the final matrix is: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dm[i][j] << "\t";
        }
        cout << endl;
    }
    Delete2DArray<int>(dm1, m, k);
    Delete2DArray<int>(dm2, k, n);
    Delete2DArray<int>(dm, m, n);
    return 0;
}

/*
 int main()
 {
 int m, n;
 int **dm;
 cout << "input matrix size m, n: ";
 cin >> m >> n;
 dm = Make2DArray<int>(m, n);
 for (int i = 0; i < m; i++) {
 for (int j = 0; j < n; j++) {
 cin >> dm[i][j];
 }
 }
 for (int i = 0; i < m; i++) {
 for (int j = 0; j < n; j++) {
 cout << dm[i][j] << "\t";
 }
 cout << endl;
 }
 Delete2DArray<int>(dm, m, n);
 return 0;
 }
 */

// 改为两个函数的形式
/*
 int **Make2DArray(int m, int n)
 {
 int **dm;
 dm = new int * [m];
 for (int i = 0; i < m; i++) {
 dm[i] = new int [n];
 if (dm[i] == NULL)
 exit(0);
 }
 return dm;
 }
 
 void Delete2DArray(int **dm, int m, int n)
 {
 for (int i = 0; i < m; i++) {
 delete[]dm[i];
 }
 delete[]dm;
 }
 
 int main()
 {
 int m, n;
 int **dm;
 cout << "input matrix size m, n: ";
 cin >> m >> n;
 dm = Make2DArray(m, n);
 for (int i = 0; i < m; i++) {
 for (int j = 0; j < n; j++) {
 cin >> dm[i][j];
 }
 }
 for (int i = 0; i < m; i++) {
 for (int j = 0; j < n; j++) {
 cout << dm[i][j] << "\t";
 }
 cout << endl;
 }
 Delete2DArray(dm, m, n);
 return 0;
 }
 */

// 课本练习
/*
 int main()
 {
	int m, n;
	int **dm;
	cout << "input matrix size m, n: ";
	cin >> m >> n;
 
	dm = new int *[m];
 
	for (int i = 0; i < m; i++) {
 if ((dm[i] = new int [n]) == NULL)
 exit(0);
	}
 
	for (int i = 0; i < m; i++) {
 for (int j = 0; i < n; j++)
 cin >> dm[i][j];
	}
	for (int i = 0; i < m; i++) {
 for (int j = 0; j < n; j++)
 cout << dm[i][j] << "\t";
 cout << endl;
	}
 for (int i = 0; i <m; i++) {
 delete[]dm[i];
	}
 delete[]dm;
	return 0;
 }
 */
