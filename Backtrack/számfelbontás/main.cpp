#include <iostream>
#include <cstdio>
#include <string>

#define N 16

using namespace std;

void kiVektor(int n, int v[]){
    for (int i = 0; i < n; ++i) {
        if(v[i])
            printf("%d ", v[i]);
    }
    printf("\n");
}

int osszegVektor(int n, int v[]){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s+= v[i];
    }
    return s;

}

void backtracking(int n, int v[], int ind){
    if(osszegVektor(n, v) == n){
        kiVektor(n, v);
        return;
    } else if (osszegVektor(n, v) > n or ind >= n) {
        return;
    } else{
        for (int i = 1; i <=n; ++i) {
            v[ind] = i;
            backtracking(n, v, ind+1);
            v[ind] = 0;
        }
    }
}

int main(){
    int n = 5;
    int v[N] = {0};
    backtracking(n, v, 0);
}
