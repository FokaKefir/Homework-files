#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("file.in");

    int n, k;
    int a[25][25];
    fin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
        }
    }

    int elso = a[k][1];
    for (int i = 1; i <= k-2; ++i) {
        a[k][i] = a[k][i+1];
    }
    a[k][k-1] = elso;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
/*
6 4
1 2 3 4 5 6
6 7 8 9 0 1
2 4 6 8 0 2
1 3 5 7 9 5
6 2 7 4 5 7
3 9 4 8 5 7
*/
