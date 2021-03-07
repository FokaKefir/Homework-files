#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m = 0;
    int v[120];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 0){
            v[m] = x;
        } else {
            v[m] = 0;
            m++;
            v[m] = 0;
        }

        m++;
    }

    for (int i = 0; i < m; ++i) {
        cout << v[i] << ' ';
    }

}
/*
6
1 0 5 0 0 7
*/