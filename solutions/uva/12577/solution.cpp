#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; int k = 1;
    while(cin >> s && s != "*"){
        cout << "Case " << k << ": ";
        if(s == "Hajj")cout << "Hajj-e-Akbar";
        else cout << "Hajj-e-Asghar"; cout << endl, k++;
    }
    return 0;
}