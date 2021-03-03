#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    int a[12][12] = {0};
    int v[12] = {0};
    bool ok = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                v[j]++;
            else{
                if (a[n][j] == 0)
                    a[n][j] = 1;
                a[n][j] *= a[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0){
                if (v[j] > 1)
                    cout << "0 ";
            } else {
                int sz = a[n][j] / a[i][j];
                if (a[i][j] % sz == 0) {
                    ok = false;
                    cout << a[i][j] << ' ';
                }
            }
        }
    }

    if (ok)
        cout << "NU EXISTA";
}
/*
4
1 1 2 9
9 2 3 3
8 4 1 1
0 2 9 3
*/