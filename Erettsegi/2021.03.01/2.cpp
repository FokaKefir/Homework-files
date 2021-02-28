#include <iostream>
#include <fstream>
using namespace std;

void sub(int n, int m, int a[], int b[]) {
    int n1 = 0;
    int m1 = 0;
    int vn = 0;
    int elozo = 0;
    while (n1 < n and m1 < m) {
        if (a[n1] < b[m1]) {
            if ((vn > 0 and elozo % 2 != a[n1] % 2) or vn == 0) {
                cout << a[n1] << ' ';
                elozo = a[n1];
                vn++;
            }
            n1++;
        } else {
            if ((vn > 0 and elozo % 2 != b[m1] % 2) or vn == 0) {
                cout << b[m1] << ' ';
                elozo = b[m1];
                vn++;
            }
            m1++;
        }
    }
    if (n1 < n and elozo % 2 != a[n1] % 2){
        cout << a[n1] << ' ';
    }
    if (m1 < m and elozo % 2 != b[m1] % 2){
        cout << b[m1] << ' ';
    }
}

int main() {
    int n = 5;
    int a[] = {2,4,8,10,14};
    int m = 3;
    int b[] = {3,5,11};
    sub(n, m, a, b);
}