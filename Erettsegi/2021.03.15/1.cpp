#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char s[300];
    gets(s);

    int ind = 0;
    int eVege;
    while (s[ind] != ' '){
        ind++;
    }
    eVege = ind - 1;
    int uEleje = 0;
    int uVege;
    ind++;
    while (ind < strlen(s)) {
        if (s[ind] != ' ' and uEleje == 0)
            uEleje = ind;
        if (s[ind] == ' '){
            uVege = ind - 1;
            if (s[eVege] == s[uVege]) {
                char stmp[100] = " succes ";
                strcpy(s+eVege+1, strcat(stmp, s+uEleje));
                ind += 6;
            }
            eVege = ind - 1;
            uEleje = 0;
        }
        ind++;
    }
    uVege = ind-1;
    if (s[eVege] == s[uVege]) {
        char stmp[100] = " succes ";
        strcpy(s+eVege+1, strcat(stmp, s+uEleje));
    }

    cout << s;

}
