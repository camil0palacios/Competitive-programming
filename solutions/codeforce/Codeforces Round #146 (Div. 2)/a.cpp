#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        bool used[26];
        memset(used, 0, sizeof used);
        int dist = 0;
        for(int i = 0; i < s.size(); i++){
            if(!used[s[i]-'a'])dist++;
            used[s[i]-'a'] = 1;
        }
        if(dist % 2 == 0)cout << "CHAT WITH HER!" << endl;
        else cout << "IGNORE HIM!" << endl;
    }
    return 0;
}