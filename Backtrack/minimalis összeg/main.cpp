#include <iostream>
#include <cstdio>
#include <string>

#define N 10
#define DUPLA 1
#define NEM_DUPLA 0

using namespace std;

int n = 5;
int mat[N][N];

// region 0. alap fuggvenyek

void be(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void kiEredmeny(int mini, int v[]){
    printf("minimalis osszeg: %d\n", mini);
    for (int i = 0; i < n; ++i) {
        int j = v[i];
        printf("%d %d: %d\n", i+1, j+1, mat[i][j]);
    }
}

// endregion

// region 1. modszer

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

int matrixOssz(){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s += mat[i][j];
        }
    }
    return s;
}

int szamolOsszeg(int n, int v[]){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int j = v[i] - 1;
        s += mat[i][j];
    }
    return s;
}

void masolVector(int n, int er[], int v[]){
    for (int i = 0; i < n; ++i) {
        er[i] = v[i] - 1;
    }
}

void backtracking(int n){
    int v[N] = {0};
    int er[N];
    int index = 0;
    int mini = matrixOssz();

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
                    int ossz = szamolOsszeg(n, v);
                    if(ossz < mini){
                        mini = ossz;
                        masolVector(n, er, v);
                    }
                    v[index]++;
                }
            }
        }
    }

    kiEredmeny(mini, er);
}

// endregion

// region 2. modszer

int szamolOsszeg2(int n, int v[]){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int j = v[i];
        s += mat[i][j];
    }
    return s;
}

void rekBacktracking(int n, int ind, int v[], bool b[], int &mini, int er[]){
    if(n == ind){
        int osszeg = szamolOsszeg2(n, v);
        if(osszeg < mini){
            mini = osszeg;
            for (int i = 0; i < n; ++i) {
                er[i] = v[i];
            }
        }
    }else{
        for (int i = 0; i < n; ++i) {
            if(b[i] == 0){
                b[i] = 1;
                v[ind] = i;
                rekBacktracking(n, ind+1, v, b, mini, er);
                b[i] = 0;
            }
        }
    }
}

void backrtacking2(){
    int v[N] = {0};
    int er[N];
    bool b[N] = {0};
    int mini = matrixOssz();
    rekBacktracking(n, 0, v, b, mini, er);
    kiEredmeny(mini, er);
}

// endregion

int main(){
    freopen("file.in", "r", stdin);
    be();

    //1. modszer
    //backtracking(n);

    //2. modszer
    backrtacking2();

}