#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1010;
vector<int> g[MXN], rg[MXN];
vector<pair<int,int>> g2[MXN];
bool vis[MXN], vids[MXN];
int who[MXN], p[MXN];
stack<int> stk;

int find(int u){ return u == p[u] ? u : p[u] = find(p[u]); } 

void join(int u, int v) {
    int a = u, b = v;
    u = find(u), v = find(v);
    if(u != v) p[v] = u;
}

void dfs1(int u) {
    vis[u] = 1;
    for(auto & v : g[u]) {
        if(!vis[v]) dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u, int rep) {
    vis[u] = 1;
    who[u] = rep;
    for(auto & v : rg[u]) {
        if(!vis[v]) dfs2(v, rep);
    }
}

int tin[MXN], low[MXN], timer, bridge;

void dfs3(int u) {
    tin[u] = low[u] = ++timer;
    for(auto & to : g2[u]) {
        int v = to.first, id = to.second;
        if(vids[id]) continue;
        if(!tin[v]) {
            vids[id] = 1;
            dfs3(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) bridge++;
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

void clear(int n) {
    for(int i = 0; i < n; i++) {
        g[i].clear();
        rg[i].clear();
        g2[i].clear();
        tin[i] = low[i] = 0;
        p[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; 
    while(cin >> n >> m) {
        clear(n);
        for(int i = 0; i < m; i++) {
            int u, v, t; cin >> u >> v >> t;
            if(i == 0) continue;
            u--, v--;
            g[u].emplace_back(v);
            rg[v].emplace_back(u);
            if(t == 2) {
                g[v].emplace_back(u);
                rg[u].emplace_back(v);
            }
            join(u, v);
        }
        set<int> s;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; i++) {
            s.insert(find(i));
            if(!vis[i]) dfs1(i);
        }
        memset(vis, 0, sizeof vis);
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if(!vis[u]) dfs2(u, u);
        }
        int cnt = 0, ids = 0;
        for(int i = 0; i < n; i++) {
            for(auto & v : g[i])
                if(who[v] != who[i]) {
                    g2[who[i]].emplace_back(who[v], ids);
                    g2[who[v]].emplace_back(who[i], ids);
                    ids++; 
                }
            cnt += who[i] == i;
        }
        if(m == 1 || s.size() > 1) cout << "*" << endl;
        else {
            if(cnt == 1) cout << "-" << endl;
            else {
                bridge = timer = 0;
                memset(vids, 0, sizeof vids);
                for(int i = 0; i < n; i++) {
                    if(who[i] == i && !tin[i]) dfs3(i);
                }
                if(bridge) cout << 2 << endl;
                else cout << 1 << endl;
            }
        }
    }
    return 0;
}