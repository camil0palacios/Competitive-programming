#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
const int lg = 19;
int depth[MXN];
int st[MXN][lg];
vector<int> g[MXN];

void dfs(int u = 0, int p = 0) {
    st[u][0] = p;
    for(int i = 1; i < lg; i++) {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
    for(auto & v: g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1; 
        dfs(v, u);
    }
}

int query(int u, int k) {
    for(int i = lg - 1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= k) {
            u = st[u][i];
        }
    }
    return u;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u; cin >> u;
        u--;
        g[u].emplace_back(i);
    }
    dfs();
    while(q--) {
        int x, k;
        cin >> x >> k;
        x--;
        if(k > depth[x]) cout << -1 << endl;
        else cout << query(x, depth[x] - k) + 1 << endl;
    }
    return 0;
}