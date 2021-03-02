#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a[5][7];
    for (int j = 0; j < 7; ++j) {
        a[0][j] = 1;
    }
    for (int i = 0; i < 5; ++i) {
        a[i][0] = 1;
    }
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 7; ++j) {
            a[i][j] = (a[i-1][j] + a[i][j-1]) % 10;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
