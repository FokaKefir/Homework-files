#include <iostream>
#include <fstream>
using namespace std;

void suma(int n, int &s) {
    bool b[10] = {false};
    s = 0;
    while (n) {
        if (n%2 == 1 and !b[n%10]) {
            s += n%10;
            b[n%10] = true;
        }
        n /= 10;
    }
}

int main() {
    int n, s;
    n = 4713835;
    suma(n, s);
    cout << s;
}

