#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int v[MXN];
int in[MXN], sz[MXN];
int times[MXN], t;
vector<int> g[MXN];
ll bit[MXN];

void update(int idx, int lst, int val) {
    while(idx < MXN) {
        bit[idx] -= lst;
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll ans = 0;
    while(idx > 0) {
        ans += bit[idx];
        idx -= idx & -idx;
    } 
    return ans;
}

void dfs(int u = 1, int p = -1) {
    times[u] = ++t;
    update(t, 0, v[u]);
    sz[u] = 1;
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }    
    dfs();
    for(int i = 0; i < q; i++) {
        int op, u;
        cin >> op >> u;
        if(op == 1) {
            int val;
            cin >> val;
            update(times[u], v[u], val);
            v[u] = val;
        } else {
            int l = times[u], r = l + sz[u] - 1;
            cout << query(r) - query(l - 1) << endl;
        }
    }
    return 0;
}