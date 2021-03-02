#include <iostream>
#include <fstream>
using namespace std;

int interval(int a[], int n) {
    int mini = min(a[0], a[n-1]);
    int maxi = max(a[0], a[n-1]);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (mini <= a[i] and a[i] <= maxi)
            s++;
    }
    return s;
}

int main() {
    int n = 6;
    int a[] = {12,27,6,8,9,2};
    cout << interval(a, n);
}
