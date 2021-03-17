#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int main() {
    ifstream fin("BAC.IN");

    int a = 0, b = 0, c = 0;
    int x;
    while (fin >> x) {
        if (x%100 == 20) {
            if (x > a) {
                c = b;
                b = a;
                a = x;
            } else if (x > b) {
                c = b;
                b = x;
            } else if (x > c) {
                c = x;
            }
        }
    }

    printf("%d %d %d", c, b, a);

}
// 9731 50 112 20 8 16 8520 3 2520 1520
/**
 * A file vegeig olvassa be a szamokat egy x valtozoba.
 * Az a, b, c valtozokba mentem el azokat a legnagyobb szamokat amelyek 20-ra vegzodnek.
 * Ha az x nagyobb mint az egyik a harom kozul akkor beszurom ugy hogy a sorrend ne valtozzon.
 * Vegen kiiratom ezt a harom szamot a megfelelo sorrendben.
 */


