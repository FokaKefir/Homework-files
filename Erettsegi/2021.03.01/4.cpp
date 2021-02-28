#include <iostream>
#include <fstream>
using namespace std;

int P(int n, int c) {
    int h = 1;
    int m = 0;
    while (n) {
        if (n%10 != c) {
            m += h * (n%10);
            h *= 10;
        }
        n /= 10;
    }
    return m;
}

int main() {
    ifstream fin("BAC.IN");
    ofstream fout("BAC.OUT");

    int n;
    while (fin >> n){
        for (int i = 1; i <=9; i+=2) {
            n = P(n, i);
        }
        if (n)
            fout << n << ' ';
    }
}