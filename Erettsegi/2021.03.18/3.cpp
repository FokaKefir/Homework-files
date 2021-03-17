#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int main() {
    ifstream fin("bac.in");
    int elsoNegativ = -1;
    int elsoPozitiv = -1;
    int utolsoNegativ = -1;
    int utolsoPozitiv = -1;

    int x;
    int ind = 0;
    while (fin >> x) {
        if (x >= 0) {
            if (elsoPozitiv == -1)
                elsoPozitiv = ind;
            utolsoPozitiv = ind;
        } else {
            if (elsoNegativ == -1)
                elsoNegativ = ind;
            utolsoNegativ = ind;
        }
        ind++;
    }

    int maxi = max(utolsoNegativ - elsoPozitiv, utolsoPozitiv - elsoNegativ) + 1;
    cout << maxi;

}


