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

int rek(int pont){

    if(pont == 0)
        return -1;

    else{
        int bal = v[pont].bal;
        int bHossz = rek(bal);

        int jobb = v[pont].jobb;
        int jHossz = rek(jobb);

        return max(jHossz, bHossz) + 1;
    }

}

int main(){
    freopen("file.in", "r", stdin);
    be();
    printf("%d ", rek(k));


}