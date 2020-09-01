#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define ll long long
using namespace std;
 
const int MXN = 10010;
const int LG = 15;
int depth[MXN], st[MXN][LG];
ll sum[MXN];
vector<pair<int, int>> g[MXN];
 
void dfs(int u, int p) {
    st[u][0] = p;
    for(int i = 1; i < LG; i++) {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
    for(auto & e: g[u]) {
        int v = e.ft, w = e.sd;
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        sum[v] = sum[u] + w;
        dfs(v, u);  
    }
}
 
int findkth(int u, int d) {
    d--;
    for(int i = LG - 1; i >= 0; i--) {
        if((1 << i) <= d) {
            u = st[u][i];
            d -= (1 << i);
        }
    }
    return u;
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
    int t;
    cin >> t;
    bool new_line = 0;
    while(t--) {
        if(new_line) cout << endl;
        new_line = 1;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            g[i].clear();
            depth[i] = sum[i] = 0;
            memset(st[i], 0, sizeof st[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        dfs(0, 0);
        string q;
        while(cin >> q && q != "DONE") {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int lc = lca(u, v);
            if(q == "DIST") {
                cout << sum[u] + sum[v] - 2*sum[lc] << endl;  
            } else {
                int k;
                cin >> k;
                int d1 = depth[u] - depth[lc] + 1;
                if(k <= d1) {
                    cout << findkth(u, k) + 1 << endl;
                } else {
                    int d2 = depth[v] - depth[lc];
                    k -= d1;
                    k = d2 - k + 1;
                    cout << findkth(v, k) + 1 << endl;
                }
            }
        }
    }
    return 0;
}  