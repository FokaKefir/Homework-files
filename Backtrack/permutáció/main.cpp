#include <iostream>
#include <cstdio>
#include <string>

#define N 16
#define DUPLA 1
#define NEM_DUPLA 0

using namespace std;

void kiVektor(int n, int v[]){
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

bool dupla(int n, int v[], int k){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == k)
            s++;
    }
    if(s==1)
        return NEM_DUPLA;
    else
        return DUPLA;

}

void backtracking(int n){
    int v[N] = {0};
    int index = 0;
    v[index] = 1;
    while(index >= 0){
        if(v[index] > n){
            v[index] = 0;
            index--;
            v[index]++;
        }else{
            if(dupla(n, v, v[index]) == DUPLA){
                v[index]++;
            } else{
                if(index < n-1){
                    v[++index] = 1;
                }else{
                    kiVektor(n, v);
                    v[index]++;
                }
            }
        }
    }
}

int main(){
    int n = 5;
    backtracking(n);
}
