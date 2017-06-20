#include <iostream>
using namespace std;

template <class T>
T **Make2DArray(int m, int n)
{
    int **dm;
    dm = new T *[m];
    for (int i = 0; i < m; i++) {
        dm[i] = new T[n];
        if (dm[i] == NULL)
            exit(0);
    }
    return (T**) dm;
}

template <class T>
void Delete2DArray(T **dm, int m, int n)
{
    for (int i = 0; i < m; i++) {
        delete[]dm[i];
    }
    delete[]dm;
}
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
    return **dm;
}

void Delete2DArray(int **dm, int m, int n)
{
    for (int i = 0; i < m; i++) {
        delete[]dm[i];
    }
    delete[]dm;
}
*/

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
    Delete2DArray<int>(**dm, m, n);
    return 0;
}

/*
int main()
{
    int m, n;
    int **dm;
    cout << "input matrix size m, n: ";
    cin >> m >> n;
    dm = new int * [m];
    for (int i = 0; i < m; i++) {
        if ((dm[i] = new int [n]) == NULL)
            exit(0);
    }
    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dm[i][j];
        }
    }
    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dm[i][j] << "\t";
        }
        cout << endl;
    }
    for (i = 0; i < m; i++) {
        delete[]dm[i];
    }
    delete[]dm;
    return 0;
}
*/
