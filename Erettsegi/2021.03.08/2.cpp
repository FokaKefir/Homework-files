#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("matrice.txt");

    int n, s = 0;
    int v[120];
    int a[12][12];

    fin >> n;
    for (int i = 0; i < n * n; ++i) {
        fin >> v[i];
    }

    for (int k = 0; k < n / 2; ++k) {
        for (int j = k; j < n - 1 - k; ++j) {
            a[k][j] = v[s];
            s++;
        }
        for (int i = k; i < n - 1 - k; ++i) {
            a[i][n-1-k] = v[s];
            s++;
        }
        for (int j = n - 1 - k; j >= 1 + k; --j) {
            a[n-1-k][j] = v[s];
            s++;
        }
        for (int i = n - 1 - k; i >= 1 + k; --i) {
            a[i][k] = v[s];
            s++;
        }
    }

    if (n % 2 == 1){
        a[n/2][n/2] = v[s];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
/*
4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/
