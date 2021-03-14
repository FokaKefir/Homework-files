#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    int a[25][25];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        int k = n - i - 1;
        while (k > 0) {
            a[i][j] = k;
            k--;
            j++;
        }
        while (k <= i){
            a[i][j] = k;
            k++;
            j++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
