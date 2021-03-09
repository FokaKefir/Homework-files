#include <iostream>
#include <fstream>
using namespace std;

int putere(int n, int p) {
    if (n%p == 0){
        int s = 0;
        while (n%p == 0){
            n /= p;
            s++;
        }
        return s;
    } else
        return -1;
}

int main() {
    cout << putere(80, 2);
}

