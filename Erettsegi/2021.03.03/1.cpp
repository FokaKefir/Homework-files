#include <iostream>
#include <fstream>
using namespace std;

int nz(int n) {
    int sz2 = 0;
    int sz5 = 0;
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0)
            sz2++;
        if (i % 5 == 0)
            sz5++;
    }
    return min(sz2, sz5);
}

int main() {
    int k;
    cin >> k;
    int n = 1;
    while (nz(n) != k)
        n++;
    cout << n;
}
