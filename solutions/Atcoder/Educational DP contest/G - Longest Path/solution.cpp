#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> g[100005];
int dp[100005];
bool vis[100005];

int dfs(int u){
    if(dp[u] != -1)return dp[u];
    vis[u] = 1;
    int ans = 0;
    for(auto & v : g[u]){
        ans = max(ans, dfs(v) + 1);
    }
    return dp[u] = ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
    }
    memset(vis, 0, sizeof vis);
    memset(dp, -1, sizeof dp);
    int mmax = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            mmax = max(mmax, dfs(i));
        }
    }
    cout << mmax << endl;
    return 0;
}
