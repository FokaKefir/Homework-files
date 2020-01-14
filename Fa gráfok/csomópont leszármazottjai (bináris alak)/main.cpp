#include <iostream>
#include <cstdio>

#define M 105

using namespace std;

int v[M];
int n;
int k;

void be(){
    scanf("%d", &n);
    for (int i = 1; i <=n; ++i) {
        int pont, ertek;
        scanf("%d%d", &pont, &ertek);
        v[pont] = ertek;
    }
    scanf("%d", &k);

}

int keresPontErtekSzerint(int ertek){
    for (int i = 1; i <=n; ++i) {
        if(v[i] == ertek)
            return i;
    }
    return NULL;
}

void rek(int pont){
    int ertek = v[pont];
    int balErtek = ertek<<1;
    int jobbErtek = (ertek<<1) + 1;

    int bal = keresPontErtekSzerint(balErtek);
    int jobb = keresPontErtekSzerint(jobbErtek);
    if(bal != NULL) {
        printf("%d ", bal);
        rek(bal);
    }
    if(jobb != NULL) {
        printf("%d ", jobb);
        rek(jobb);
    }

}



int main(){
    freopen("file.in", "r", stdin);
    be();
    rek(k);

}