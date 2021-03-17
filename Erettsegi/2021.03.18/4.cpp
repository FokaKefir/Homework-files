#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int main() {
    ifstream fin("bac.in");

    int x;
    int n, db;
    bool ok = true;
    fin >> x;
    n = x;
    db = 1;
    while (fin >> x) {
        if (x == n) {
            db ++;
        } else {
            if (db == 2){
                cout << n << ' ';
                ok = false;
            }
            n = x;
            db = 1;
        }
    }
    if (db == 2){
        cout << n << ' ';
        ok = false;
    }

    if (ok) {
        cout << "nu exista";
    }
}
// 100 50 50 50 49 49 36 16 16 12 10 10 9 7 7
/**
 * Beolvasom a szamokat az allomany vegeig x valtozoba, mindig nezem hogy megfelel-e az elozovel, ha igen akkor novelem a db-ot.
 * db azt jeloli hogy hanyszor foldult elo az adott szam.
 * Mikor jon egy kulonbozo szam megviszgalom, hogy hanyszor fordult elo az elozo szam eddig,
 * ha 2-szer akkor azt a szamot kiiratom es az ok-t hamisra teszem.
 * Ha az ok igaz akkor nem volt megoldas, tehat kiiratom a "nu exista" uzenetet.
 */

