#include <iostream>
#include <fstream>
using namespace std;

int sub(int v[], int n, int a) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] < a)
            s++;
    }
    return s;
}

int main() {
    int n;
    int v[105];
    string message = "DA";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        if (sub(v, n, v[i]) != sub(v, n, v[i]+1) - 1){
            message = "NU";
            break;
        }
    }
    cout << message;
}