#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        bool flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'H')flag = 1;
            if(s[i] == '9')flag = 1;
            if(s[i] == 'Q')flag = 1;
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}