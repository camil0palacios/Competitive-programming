#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        cout << char(toupper(s[0]));
        int i = 1;
        while(s[i]){
            cout << s[i];
            i++;
        }
        cout << endl;
    }
    return 0;
}

/*  in
ApPLe
konjac
*/