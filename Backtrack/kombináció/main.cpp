#include <iostream>
#include <cstdio>
#include <string>

#define N 15
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

void backtracking(int n, int p){
    int v[N]={0};
    int index = 0;
    v[index] = 1;
    while(index>=0){
        if(v[index] > (n-p+index+1)){
            v[index] = 0;
            index--;
            v[index]++;
        }else {
            if (dupla(p, v, v[index]) == DUPLA) {
                v[index]++;
            } else {

                if(index < p-1){
                    index++;
                    v[index] = v[index - 1] + 1;
                }else{
                    kiVektor(p, v);
                    v[index]++;
                }

            }
        }
    }
}

int main(){
    freopen("file.in", "r", stdin);
    int n = 7, p = 3;
    backtracking(n, p);

}