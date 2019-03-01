#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int a = 0, b = s.size() - 1;
        for(int i = 0; s[i] != '[' && i < s.size(); i++)a++;
        for(int i = a; s[i] != ':' && i < s.size(); i++)a++;
        for(int i = s.size() - 1; s[i] != ']' && i >= 0; i--)b--;
        for(int i = b; s[i] != ':' && i >= 0; i--)b--;
        //cout << a << " " << b << endl;
        int l = 0;
        for(int i = a; i <= b; i++){
            if(s[i] == '|')l++;
        }
        if(a < b)cout << l + 4 << endl;
        else cout << -1 << endl;
    }
    return 0;
}