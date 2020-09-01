#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int sz[MXN], depth[MXN];
ll ans[MXN];
vector<int> g[MXN];

void dfs(int u, int p) {
    sz[u] = 1;
    for(auto & v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0, 0);
    for(int i = 0; i < n; i++) {
        ans[i] = depth[i] - (sz[i] - 1);
    }
    sort(ans, ans + n, greater<int>());
    ll res = 0;
    for(int i = 0; i < k; i++) {
        res += 1LL * ans[i];
    }
    cout << res << endl;
    return 0;
}