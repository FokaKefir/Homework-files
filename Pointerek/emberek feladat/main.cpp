#include <iostream>
#include <cstdio>
#include <string>

#define NO 0
#define FERFI 1
using namespace std;

struct Ember{
    bool nem;
    string vezeteknev;
    string keresztnev;
    float magassag;
    float suly;

};

void be(int n, Ember* &emberek){
    cin>>n;
    emberek = new Ember[n];

    for (int i = 0; i < n; ++i) {
        Ember ember;
        cin>>ember.nem>>ember.vezeteknev>>
        ember.keresztnev>>ember.magassag>>
        ember.suly;
        emberek[i] = ember;
    }
}

void kiEmberek(int n, Ember* emberek){
    for (int i = 0; i < n; ++i) {
        cout<<emberek[i].vezeteknev<<' '<<emberek[i].keresztnev<<'\n';
    }
}

int main(){
    freopen("file.in", "r", stdin);
    int n;
    Ember* emberek;
    be(n, emberek);
    kiEmberek(n, emberek);

}