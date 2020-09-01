#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '7' || s[i] == '4')ans++;
        }
        if(ans == 4 || ans == 7)cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}