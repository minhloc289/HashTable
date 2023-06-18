

#include <iostream>
using namespace std;

void inputMatrix(int a[][50], int& n, int& m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

void outputMatrix(int a[][50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void uniqueElements(int a[][50], int n, int m) {
    int max = a[0][0];
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
    }
    int* hash = new int[max + 1];
    for (int i = 0; i < max + 1; i++) {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            hash[a[i][j]]++;
        }
    }
    for (int i = 0; i < max + 1; i++) {
        if (hash[i] == 1) {
            flag = 1;
        }
    }   
    if (flag == 1) {
        cout << "Unique elements in the matrix:\n";
        for (int i = 0; i < max + 1; i++) {
            if (hash[i] == 1) {
                cout << i << " ";
            }
        }
    }
    else {
        cout << "No unique element in the matrix";
    }
    delete[]hash;
}



int main()
{
    int m, n, a[50][50];
    inputMatrix(a, n, m);
    cout << "Matrix:\n";
    outputMatrix(a, n, m);
    uniqueElements(a, n, m);
    return 0;
}



