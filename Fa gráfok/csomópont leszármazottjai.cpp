#include <iostream>
#include <cstdio>

#define M 105

using namespace std;

struct Fa{
    int jobb;
    int bal;
}v[M];
int n;
int k;

void be(){
    scanf("%d", &n);
    for (int i = 1; i <=n; ++i) {
        scanf("%d%d", &v[i].bal, &v[i].jobb);
    }
    scanf("%d", &k);
}

void rek(int pont){
    int bal = v[pont].bal;
    int jobb = v[pont].jobb;
    if(bal != 0){
        printf("%d ", bal);
        rek(bal);
    }
    if(jobb != 0){
        printf("%d ", jobb);
        rek(jobb);
    }
}

int main(){
    freopen("file.in", "r", stdin);
    be();
    rek(k);


}