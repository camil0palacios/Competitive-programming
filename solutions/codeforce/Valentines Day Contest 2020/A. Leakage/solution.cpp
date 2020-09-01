#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2e5 + 10;
int n, m, q, tin[MAXN], low[MAXN], tim, depth[2*MAXN];
int st[2*MAXN][19], bcc, stk[MAXN], it, c[2*MAXN];
vector<int> g1[MAXN], g2[2*MAXN];

void dfs2(int u = 0, int p = 0){
    st[u][0] = p;
    for(int i = 1; i < 19; i++){
        st[u][i] = st[st[u][i-1]][i-1];
    }
    c[u] += u < n;
    for(auto & v: g2[u]){
        c[v] = c[u];
        depth[v] = depth[u] + 1;
        dfs2(v, u);
    }
}

void dfs1(int u = 0, int p = 0){
    tin[u] = low[u] = ++tim;
    stk[it++] = u;
    for(auto & v : g1[u]){
        if(v == p)continue;
        if(!tin[v]){
            dfs1(v, u);
            if(low[v] >= tin[u]){
                g2[u].emplace_back(n + bcc);
                do { 
                    g2[n + bcc].emplace_back(stk[it - 1]);
                } while(stk[--it] != v);
                bcc++;
            }
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], tin[v]);
        }
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    for(int i = 18; i >= 0; i--){
        if(depth[u] - (1 << i) >= depth[v]){
            u = st[u][i];
        }
    }
    if(u == v)return u;
    for(int i = 18; i >= 0; i--){
        if(st[u][i] != st[v][i]){
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v; u--, v--;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
    }
    dfs1();
    dfs2();
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v; u--, v--; 
        int lc = lca(u, v);
        // int dist = c[u] + c[v] - 2*c[lc];
        // cout << dist - 1 << endl;
        cout << (c[u] + c[v] - c[lc] - (lc ? c[st[lc][0]] : 0) - 2) << endl;
    }
    return 0;
}