#include <iostream>
#include <fstream>
using namespace std;

void sub(int n, int k) {
    for (int i = n; i >= 1; --i) {
        cout << k*i << ' ';
    }
}

int main() {
    sub(3, 5);
}