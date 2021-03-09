#include <iostream>
#include <fstream>

using namespace std;

int baza(int n) {
    int maxi = 0;
    while (n) {
        maxi = max(n%10, maxi);
        n /= 10;
    }
    return maxi + 1;
}

int main() {
    int n = 50731;
    cout << baza(n);
}

