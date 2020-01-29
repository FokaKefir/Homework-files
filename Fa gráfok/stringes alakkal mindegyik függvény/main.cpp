#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>

#define NINCS_LESZARMAZOTT 0;

using namespace std;

string s;
struct leszarmazott{
    int bal;
    int jobb;
};

// region 1. Secondary functions

int intFromChar(char c){
    return c-'0';
}
int intFromString(string str){
    int szam = 0;
    for (int i = 0; i < str.length(); ++i) {
        int szj = intFromChar(str[i]);
        szam = (szam * 10) + szj;
    }
    return szam;
}
bool charSzame(char c){
    if(c>='0' and c<='9')
        return true;
    else
        return false;
}
void beszurLeszarmazottba(leszarmazott &lesz, int szam){
    if(lesz.bal == 0)
        lesz.bal = szam;
    else
        lesz.jobb = szam;
}
int pontIndexe(int pont){
    string strSzam = "";
    int szam = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(charSzame(s[i])){
            strSzam.push_back(s[i]);
        } else if (strSzam.length() != 0){
            szam = intFromString(strSzam);
            strSzam = "";
        }
        if(szam == pont)
            return i;
    }
}
// endregion

// region 2. Main functions

int magassag(){
    int maxi = 0;
    int k=0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '('){
            k++;
        }else if(s[i] == ')'){
            k--;
        }

        maxi = max(maxi, k);
    }
    return maxi;
}
leszarmazott kozvetlenLeszarm(int pont){
    int index = pontIndexe(pont);
    int k=0;
    int szam;
    string strSzam = "";
    leszarmazott lesz;
    lesz.bal = 0;
    lesz.jobb = 0;

    for (int i = index; i < s.length(); ++i) {
        if(charSzame(s[i])){
            strSzam.push_back(s[i]);
        } else if (strSzam.length() != 0){
            szam = intFromString(strSzam);
            strSzam = "";
            if(k == 1){
                beszurLeszarmazottba(lesz, szam);
            }
        }

        if(s[i] == '(')
            k++;
        else if(s[i] == ')')
            k--;

        if(k == 1 and s[i] == '*'){
            szam = NINCS_LESZARMAZOTT;
            beszurLeszarmazottba(lesz, szam);
        }

        if(k == 0)
            break;
    }

    return lesz;
}

void preorder(int pont){
    if(pont == 0)
        return;
    else{
        leszarmazott lesz = kozvetlenLeszarm(pont);

        printf("%d ", pont);
        preorder(lesz.bal);
        preorder(lesz.jobb);
    }
}
void postorder(int pont){
    if(pont == 0)
        return;
    else{
        leszarmazott lesz = kozvetlenLeszarm(pont);

        postorder(lesz.bal);
        postorder(lesz.jobb);
        printf("%d ", pont);
    }
}
void inorder(int pont){
    if(pont == 0)
        return;
    else{
        leszarmazott lesz = kozvetlenLeszarm(pont);

        inorder(lesz.bal);
        printf("%d ", pont);
        inorder(lesz.jobb);
    }
}

queue<int> faLevelei(){
    string strSzam = "";
    int szam = 0;
    queue<int> levelek;

    for (int i = 0; i < s.length(); ++i) {
        if(charSzame(s[i])){
            strSzam.push_back(s[i]);
        } else if (strSzam.length() != 0){
            szam = intFromString(strSzam);
            strSzam = "";
            if(s[i] != '('){
                levelek.push(szam);
            }
        }
    }
    return levelek;
}
void kiLevelek(queue<int> v){
    while(!v.empty()){
        printf("%d ", v.front());
        v.pop();
    }
}

// endregion

int main(){
    freopen("file.in", "r", stdin);
    cin>>s;
    queue<int> levelek;
    levelek = faLevelei();
    kiLevelek(levelek);
}