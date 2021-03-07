#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("file.in");

    int n;
    int a[25][25];
    fin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    }

    for (int j = 0; j < n - 1; ++j) {
        cout << a[0][j] << ' ';
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << a[i][n-1] << ' ';
    }
    for (int j = n - 1; j >= 1; --j) {
        cout << a[n-1][j] << ' ';
    }
    for (int i = n - 1; i >= 1; --i) {
        cout << a[i][0] << ' ';
    }

}
