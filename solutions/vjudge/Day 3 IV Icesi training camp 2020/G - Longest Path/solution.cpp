#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int n, m;
int dp[MXN];
vector<int> g[MXN];

int dfs(int u) {
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(auto & v: g[u]) {
        ans = max(ans, dfs(v) + 1);
    }
    return dp[u] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    return 0;
}