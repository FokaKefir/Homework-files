#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int a = 2; a <= n/2; a+=2) {
        for (int b = 1; b <= n/2; ++b) {
            if ((a*b + a/b) == n)
                cout << a << '-' << b << ' ';
        }
    }
}

