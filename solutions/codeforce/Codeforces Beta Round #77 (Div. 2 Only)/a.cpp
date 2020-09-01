#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        bool f = 1;
        for(int i = 0; i + 7 <= s.size(); i++){
            if(s[i] == '0' && s.substr(i,7) == "0000000"){
                f = 0;
                break;
            }
            if(s[i] == '1' && s.substr(i,7) == "1111111"){
                f = 0;
                break;
            }
        }
        if(f)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}