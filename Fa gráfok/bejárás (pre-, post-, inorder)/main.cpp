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

void rekPreorder(int aktPont){
    if(aktPont == 0)
        return;
    else{
        printf("%d ", aktPont);
        int bal = v[aktPont].bal;
        rekPreorder(bal);
        int jobb = v[aktPont].jobb;
        rekPreorder(jobb);
    }
}

void rekPostorder(int aktPont){
    if(aktPont == 0)
        return;
    else{
        int bal = v[aktPont].bal;
        rekPostorder(bal);
        int jobb = v[aktPont].jobb;
        rekPostorder(jobb);
        printf("%d ", aktPont);
    }
}

void rekInorder(int aktPont){
    if(aktPont == 0)
        return;
    else{
        int bal = v[aktPont].bal;
        rekInorder(bal);
        printf("%d ", aktPont);
        int jobb = v[aktPont].jobb;
        rekInorder(jobb);

    }
}

int main(){
    freopen("file.in", "r", stdin);
    be();
    rekInorder(k);
}