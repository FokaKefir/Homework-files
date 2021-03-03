#include <iostream>
#include <fstream>

using namespace std;

int strazsa(int n, int a[12][12], int ind) {
    int s = 1;
    if (a[0][ind] % a[0][0] == 0) {
        s = a[0][ind] / a[0][0];
        for (int i = 0; i < n; ++i) {
            if (a[i][ind] % s != 0){
                s = 1;
                break;
            }
        }
    }
    return s;
}

int main() {
    int n;
    int a[12][12];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int s = 1;
    for (int j = 1; j < n; ++j) {
        s *= strazsa(n, a, j);
    }
    if (s != 1)
        cout << s;
    else
        cout << "NU EXISTA";
}
