#include <iostream>
#include <fstream>

using namespace std;

bool check(int a[100][100], int i, int j) {
    if (a[i-1][j-1]%2 == 1 and a[i-1][j]%2 == 1 and a[i-1][j+1]%2 == 1 and
            a[i][j-1]%2 == 1 and a[i][j]%2 == 1 and a[i][j+1]%2 == 1 and
            a[i+1][j-1]%2 == 1 and a[i+1][j]%2 == 1 and a[i+1][j+1]%2 == 1)
        return true;
    else
        return false;
}

int main() {
    ifstream fin("vecini.txt");

    int n;
    int a[100][100];
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        a[i][0] = a[i][n+1] = 1;
    }
    for (int j = 0; j <= n + 1; ++j) {
        a[0][j] = a[n + 1][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (check(a, i, j))
                cout << i-1 << ' ' << j-1 << '\n';
        }
    }

}
