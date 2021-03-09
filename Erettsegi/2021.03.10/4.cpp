#include <iostream>
#include <fstream>
using namespace std;



int main() {
    ifstream fin("file.in");
    int m, n;
    int maxi = 0;
    bool b1[25] = {false};
    bool b2[25] = {false};
    fin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            fin >> x;
            if (j == 0) {
                b1[x] = true;
                maxi = max(maxi, x);
            }
            if (j == n-1) {
                b2[x] = true;
                maxi = max(maxi, x);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i <= maxi; ++i) {
        if (b1[i] and b2[i]) {
            cout << i << ' ';
            ok = false;
        }
    }
    if (ok)
        cout << "nepolarizate";
}
/*
4 5
3 7 1 2 5
2 4 5 9 6
6 2 7 8 1
5 3 2 7 8
*/