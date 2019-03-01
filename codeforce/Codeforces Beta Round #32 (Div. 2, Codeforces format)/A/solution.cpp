#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int i = 0, n = s.size();
        while(i < n){
            if(s[i] == '.')i++, cout << 0;
            if( i < n && i + 1 < n){
                if(s[i] == '-' && s[i+1] == '.')i += 2, cout << 1;
                else if(s[i] == '-' && s[i+1] == '-')i += 2, cout << 2;
            }
        }
        cout << endl;
    }
    return 0;
}