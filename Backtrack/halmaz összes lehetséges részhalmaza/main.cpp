#include <iostream>
#include <cstdio>
#include <string>

#define N 16
#define DUPLA 1
#define NEM_DUPLA 0

using namespace std;

int vec[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// region 1. modszer

void kiVektor(int n, int v[]){
    for (int i = 0; i < n; ++i) {
        printf("%d ", vec[v[i] - 1]);
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
                kiVektor(index + 1, v);
                if(index < n-1){
                    v[index + 1] = v[index];
                    index++;
                }else{
                    v[index]++;
                }
            }
        }
    }
}

// endregion

// region 2. modszer

void ki(int n, bool b[]){
    for (int i = 0; i < n; ++i) {
        if(b[i]){
            printf("%d ", vec[i]);
        }
    }
    printf("\n");
}

int keresIndex(int n, bool b[]){
    for (int i = n - 2; i >= 0; --i) {
        if(b[i]==1 and b[i + 1]!=1)
            return i;
    }
    return -1;
}

int szamolEgyesek(int n, bool b[], int ind){
    int s = 0;
    for (int i = n-1; i >= ind; --i) {
        s += b[i];
    }
    return s;
}

void backtracking2(int n){
    bool b[N]={0};
    b[0] = 1;
    while(true){
        ki(n, b);
        int index = keresIndex(n, b);
        if(index != -1){
            int db = szamolEgyesek(n, b, index + 1) + 1;

            b[index] = 0;
            index++;

            while(db>0){
                b[index] = 1;
                index++;
                db--;
            }
            while(index<n){
                b[index] = 0;
                index++;
            }

        }else{
            int db = szamolEgyesek(n, b, 0) + 1;

            if(db > n)
                break;

            for (int i = 0; i < db; ++i) {
                b[i] = 1;
            }
            for (int i = db; i <n ; ++i) {
                b[i] = 0;
            }
        }
    }
}

// endregion

int main(){
    int n = 5;
    backtracking2(n);
}