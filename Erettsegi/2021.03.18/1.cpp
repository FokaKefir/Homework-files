#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ofstream fout("bac.txt");

    int x, y;
    cin >> x >> y;
    fout << y << ' ' << x << ' ';
    while (y > 1) {
        int z = 3*x - y;
        fout << z << ' ';
        y = x;
        x = z;
    }

}
// 89 233
/**
 * Az elozo szamot meg lehet hatarozni az utana kovetkezo ket szambol a 3*x-y fuggvennyel.
 * A ciklus addig megy mig az y nem lesz egy, tehat amig nem iratta ki az osszes szamot csokkeno sorrendben
 */

