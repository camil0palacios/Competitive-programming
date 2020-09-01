#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

double ans;

struct trie{
    map<char,trie> m;
    bool is_end;
    trie(): is_end(0){}
    void build(string & s, int idx){
        if(idx < s.size()){
            m[s[idx]].build(s, idx + 1);
        }else is_end = 1;
        
    }
    void dfs(int x){
        if(is_end)ans += x;
        if(m.size() >= 2 || (is_end && m.size() >= 1))x++;
        for(auto & to : m){
            to.second.dfs(x);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    while(cin >> n){
        trie root;
        for(int i = 0; i < n; i++){
            cin >> s;
            root.m[s[0]].build(s, 1);
        }
        ans = 0;
        for(auto & i : root.m){
            i.second.dfs(1);
        }
        //root.dfs(1);
        cout << fixed << setprecision(2) << (ans/(n*1.0)) << endl;
    }
    return 0;
}