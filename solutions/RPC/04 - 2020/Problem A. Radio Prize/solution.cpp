#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int n, t[MXN]; 
ll depth[MXN], sz[MXN], ts[MXN], ans[MXN];
vector<pair<int,int>> g[MXN];

void dfs1(int u, int p) {
    ts[u] = t[u];
    sz[u] = 1;
    for(auto & to : g[u]) {
        int v = to.first, w = to.second;
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v]; 
        ts[u] += ts[v];
    }
}

void dfs2(int u, int p, ll depth_sum, ll tax_depth_sum) {
    ans[u] = t[u] * depth_sum + tax_depth_sum;
    for(auto & to : g[u]) {
        int v = to.first, w = to.second;
        if(v == p) continue;
        dfs2(v, u, depth_sum + w * (n - 2 * sz[v]), tax_depth_sum + w * (ts[0] - 2 * ts[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, v);
    }
    dfs1(0, 0);
    ll depth_s = 0, tax_depth_s = 0;
    for(int i = 0; i < n; i++) {
        depth_s += depth[i];
        tax_depth_s += 1LL * ts[i] * depth[i];
    }
    dfs2(0, 0, depth_s, tax_depth_s);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}