#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
vector<int> g[MXN];
ll in[MXN], ans[MXN];
ll sz[MXN];

void dfs1(int u = 0, int p = -1) {
    sz[u] = 1;
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs1(v, u);
        in[u] += in[v] + sz[v];
        sz[u] += sz[v];
    }
}

void dfs2(int u = 0, int p = -1, ll val = 0, ll subsz = 0) {
    ans[u] = in[u] + val + subsz;
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs2(v, u, ans[u] - in[v] - sz[v], sz[0] - sz[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1();
    dfs2();
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}