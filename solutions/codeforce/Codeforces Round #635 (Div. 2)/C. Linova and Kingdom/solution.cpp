#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5; 
int n, k;
vector<int> g[MXN];
int sum[MXN], res[MXN];

void dfs(int u, int p, int depth) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        dfs(v, u, depth + 1);
        sum[u] += sum[v];
    }
    res[u] = depth - sum[u];
    sum[u]++; 
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0, 0, 0);
    sort(res, res + n);
    ll ans = 0;
    for(int i = n - 1; i >= 0 && k; i--) {
        ans += res[i]; k--;
    }
    cout << ans << endl;
    return 0;
}