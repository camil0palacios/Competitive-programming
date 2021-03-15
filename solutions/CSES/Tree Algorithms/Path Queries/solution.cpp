#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int in[MXN], out[MXN], t;
ll v[MXN];
ll bit[MXN];
vector<int> g[MXN];


void update(int idx, int val) {
    for(idx++; idx < MXN; idx += idx & -idx) 
        bit[idx] += val;
}

ll query(int idx) {
    ll ans = 0;
    for(; idx; idx -= idx & -idx)
        ans += bit[idx];
    return ans;
}

void dfs(int u = 0, int p = -1) {
    in[u] = t++;
    for(auto & v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    out[u] = t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;  
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs();
    for(int i = 0; i < n; i++) {
        update(in[i], v[i]), update(out[i], -v[i]);
    }
    for(int i = 0; i < q; i++) {
        int op, u;
        cin >> op >> u;
        u--;
        if(op == 1) {
            int val;
            cin >> val;
            update(in[u], val-v[u]);
            update(out[u], v[u]-val);
            v[u] = val;
        } else {
            cout << query(in[u] + 1) << endl;
        }   
    }
    return 0;
}