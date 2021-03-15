#include <iostream>
#include <fstream>

using namespace std;

// 1. feladat
struct koord {
    int x;
    int y;
};

struct triunghi {
    koord A;
    koord B;
    koord C;
};

// 2. feladat
struct specie {
    int cod;
    int nrExemplare;
    int varsta[];
};

// 3. feladat
struct szogek {
    float FataMuchie;
    float FataFata;
};

struct poliedru{
    int NrVarfuri;
    float Muchie;
    szogek Unghi;
};

// 4. feladat
struct complex {
    float pre;
    float pim;
};

struct ecuatie {
    int numar;
    complex solutie[100];
};

// 5. feladat
struct cerc {
    float raza;
    koord centru;
};

int main() {
    // 1. feladat
    triunghi t;

    // 2. feladat
    specie s[10];

    // 3. feladat
    poliedru p;

    // 4. feladat
    ecuatie e;

    // 5. feladat
    cerc fig;

}

