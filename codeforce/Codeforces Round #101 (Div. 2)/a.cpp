#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b, c;
    while(cin >> a >> b >> c){
        int used[26], comp[26];
        memset(used, 0, sizeof used);
        memset(comp, 0, sizeof comp);
        for(auto & i : a)used[i-'A']++;
        for(auto & i : b)used[i-'A']++;
        for(auto & i : c)comp[i-'A']++;
        bool flag = 1;
        for(int i = 0; i < 26; i++){
            if(used[i] != comp[i])
                flag = 0;
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}