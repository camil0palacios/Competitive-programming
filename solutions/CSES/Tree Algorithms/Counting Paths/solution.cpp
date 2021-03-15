#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
const int LG = 19;
int st[MXN][LG];
int depth[MXN];
int cnt[MXN];
int ans[MXN];
vector<int> g[MXN];

void dfs(int u = 0, int p = -1) {
    for(auto & v: g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        st[v][0] = u;
        for(int i = 1; i < LG; i++) {
            st[v][i] = st[st[v][i - 1]][i - 1];
        }
        dfs(v, u);
    }
}

void dfs2(int u = 0, int p = -1) {
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs2(v, u);
        cnt[u] += cnt[v];
    }
    ans[u] = cnt[u];
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = LG - 1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            u = st[u][i];
        }
    }
    if(u == v) return u;
    for(int i = LG - 1; i >= 0; i--) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs();
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lc = lca(u, v);
        cnt[u]++, cnt[v]++;
        cnt[lc]--;
        if(lc) cnt[st[lc][0]]--;
    }
    dfs2();
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}