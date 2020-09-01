#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
vector<int> g[NMAX];
int dp[NMAX];
bool vis[NMAX];

void dfs(int u){
    vis[u] = 1;
    int num = 0;
    vector<int> tmp;
    for(auto & to : g[u]){
        if(!vis[to]){
            num++;
            dfs(to);
            tmp.push_back(dp[to]);
        }
    }
    if(num == 0)dp[u] = 0;
    else{
        dp[u] = 0;
        sort(tmp.begin(), tmp.end(), greater<int>());
        for(int i = 1; i <= num; ++i){
            dp[u] = max(dp[u], tmp[i-1] + i);
        }
    }
}

int main(){
    int n, k;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        while(cin >> k){
            if(k == 0)break;
            g[i].push_back(k);
            g[k].push_back(i);
        }
    }
    cin >> k;
    dfs(k);
    cout << dp[k] << endl;
    return 0;
}