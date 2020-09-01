#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        vector<string> v(5);
        for(auto &i : v)cin >> i;
        bool flag = 0;
        for(auto & i : v){
            if(i[0] == s[0] || i[1] == s[1])
                flag = true;
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}