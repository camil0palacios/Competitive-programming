#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        bool h, e, o;
        int ll;
        h = e = ll = o = 1;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'h' && h)ans += 'h', h = 0;
            if(s[i] == 'e' && e && !h)ans += 'e', e = 0;
            if(s[i] == 'l' && ll <= 2 && !e)ans += 'l', ll++;
            if(s[i] == 'o' && o && ll == 3)ans += 'o', o = 0;
        }
        if(ans == "hello")cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}