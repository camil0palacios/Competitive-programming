// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MXN = 20010;
const int inf = 1e9;
vector<int> g[MXN];
int dp[MXN], son[MXN];

void dfs(int u, int p = 0){
    dp[u] = 1;
    son[u] = 0;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == p) continue;
        dfs(v, u);
        dp[u] += dp[v];
        if(son[u] < dp[v]) {
            son[u] = dp[v];
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            g[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v; u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        int id = 0, mx = son[0];
        for(int i = 0; i < n; i++) {
            if(mx > max(son[i], dp[0] - dp[i])) {
                mx = max(son[i], dp[0] - dp[i]);
                id = i;
            }
        }
        cout << id + 1 << ' ' << mx << endl;
    }
    return 0;
}