#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> g;
map<string,int> dp;

void dfs(string u, string p){
    dp[u] = 1;
    for(auto & to : g[u]){
        if(to == p)continue;
        dfs(to,u);
        dp[u] = max(dp[u], dp[to] + 1);
    }
}

void to_lower(string & s){
    for(int i = 0; i < (int)s.size(); ++i){
        s[i] = tolower(s[i]);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2 >> s2;
        to_lower(s1);
        to_lower(s2);
        g[s2].emplace_back(s1);
        g[s1].emplace_back(s2);
    }
    dfs("polycarp", "polycarp");
    cout << dp["polycarp"] << endl;
    return 0;
}