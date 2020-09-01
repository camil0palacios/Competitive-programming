#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define mp make_pair
using namespace std;

const int MXN = 1e5 + 5;
const int LG = 18;
int depth[MXN];
int st[MXN][LG];
int mx[MXN][LG];
int p[MXN];
vector<pair<int, pair<int,int>>> edges;
vector<pair<int,int>> g[MXN];

void dfs(int u, int par = 0) {
    st[u][0] = par;
    for(int i = 1; i < LG; i++) {
        st[u][i] = st[st[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[st[u][i - 1]][i - 1]);
    }
    for(auto & to : g[u]) {
        int v = to.ft, w = to.sd;
        if(v == par) continue;
        depth[v] = depth[u] + 1;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = LG - 1; i >= 0; i--) 
        if(depth[u] - (1 << i) >= depth[v])
            u = st[u][i];
    if(u == v) return u;
    for(int i = LG - 1; i >= 0; i--) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i]; 
        }
    }
    return st[u][0];
}

int max_edge(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int ans = 0;
    for(int i = LG - 1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            ans = max(ans, mx[u][i]);
            u = st[u][i];
        }
    }
    return ans;
}

int get_max(int u, int v) {
    int x = lca(u, v);
    return max(max_edge(u, x), max_edge(v, x));
}

int find(int a) {
    return a == p[a] ? a : p[a] = find(p[a]);
}

bool join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        p[b] = a;
        return 0;
    }
    return 1;
}

int kruskal() {
    int mst = 0;
    sort(edges.begin(), edges.end());
    for(auto & e : edges) {
        int u = e.sd.ft, v = e.sd.sd, w = e.ft;
        if(!join(u, v)) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
            mst += w;
        }
    }
    return mst;
}

pair<int, int> ord(int u, int v) {
    return mp(min(u, v), max(u, v));
}

void clear(int n) {
    edges.clear();
    for(int i = 0; i < n; i++) {
        g[i].clear();
        p[i] = i;
        depth[i] = 0;
        memset(st[i], 0, sizeof st[i]);
        memset(mx[i], 0, sizeof mx[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q;
    while(cin >> n >> m) {
        clear(n);
        map<pair<int, int>, int> cost;
        for(int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            edges.emplace_back(w, mp(u, v));
            cost[ord(u, v)] = w;
        }
        int mst = kruskal();
        dfs(0);
        cin >> q;
        for(int i = 0; i < q; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            cout << mst + cost[ord(u, v)] - get_max(u, v) << endl; 
        }
    }
    return 0;
}