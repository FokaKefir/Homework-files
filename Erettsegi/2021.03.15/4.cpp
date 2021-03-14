#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n;
    char mat[21][25];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
    char pre[25];
    strcpy(pre, mat[n-1]);
    for (int i = 0; i < n - 1; ++i) {
        if (strcmp(mat[i], strstr(mat[i], pre)) == 0)
            cout << mat[i] << ' ';
    }

}
/*
6
raita
grai
raid
raion
straie
rai
*/
