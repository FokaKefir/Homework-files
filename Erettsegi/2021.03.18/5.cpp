#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int main() {
    ifstream fin("bac.txt");

    int x;
    int maxi = 0;
    int sum = 0;
    while (fin >> x) {
        if (sum + x > 0) {
            sum += x;
            maxi = max(maxi, sum);
        } else {
            sum = 0;
        }
    }
    cout << maxi;
}
//4 -6 7 2 -1 4 -10 -3 9 2 -2
/**
 * Beolvassuk a szamokat az x valtozoba egyesevel.
 * Ha a sum es az o osszege nagyobb mint 0 akkor hozzaadjuk a sum-hoz es vizsgaljuk, hogy nagyobb-e mint a maxi.
 * Kulonben a sum-ot lenullazzuk.
 * Kiiratjuk a maxit.
 */


