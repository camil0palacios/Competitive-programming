#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k = 1;
    while(cin >> s && s[0] != '#'){
        cout << "Case "<< k << ": ";
        if(s == "HELLO")cout << "ENGLISH";
        else if(s == "HOLA")cout << "SPANISH";
        else if(s == "HALLO")cout << "GERMAN";
        else if(s == "BONJOUR")cout << "FRENCH";
        else if(s == "CIAO")cout << "ITALIAN";
        else if(s == "ZDRAVSTVUJTE")cout << "RUSSIAN";
        else cout << "UNKNOWN";
        cout << endl;
        k++;
    }
    return 0;
}