#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    string s;
    while(cin >> k >> s){
        map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.count(s[i]))m[s[i]]++;
            else m[s[i]] = 1;
        }
        bool f = 1;
        for(auto & i : m){
            if(i.second % k != 0)f = 0;
        }
        int ans = 0;
        if(f){
            string ns;
            for(auto & i: m){
                ns += string(i.second / k, i.first);
            }
            for(int i = 0; i < k; i++){
                cout << ns;
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}