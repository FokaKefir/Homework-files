#include <iostream>
#include <fstream>

using namespace std;

bool check(bool a[22][22], int m, int j) {
    for (int i = 0; i < m; ++i) {
        if (a[i][0] == a[i][j])
            return false;
    }
    return true;
}

int main() {
    ifstream fin("file.in");
    int n, m;
    bool a[22][22];
    fin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> a[i][j];
        }
    }

    int s = 0;
    for (int j = 1; j < n; ++j) {
        s += check(a, m, j);
    }

    cout << s;
}

