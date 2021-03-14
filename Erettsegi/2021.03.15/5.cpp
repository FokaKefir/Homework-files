#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ifstream fin("cuvinte.txt");

    int n = 0;
    char s[25];
    char mat[100][25];
    while (fin >> s) {
        strcpy(mat[n++], s);
    }

    bool ok = true;
    int k = n;
    while (ok) {
        ok = false;
        for (int i = 0; i < k - 1; ++i) {
            if (strlen(mat[i]) > strlen(mat[i+1])) {
                swap(mat[i], mat[i+1]);
                ok = true;
            }
        }
        k--;
    }

    for (int i = 0; i < n; ++i) {
        cout << mat[i] << '\n';
    }
}

