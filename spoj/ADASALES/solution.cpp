#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int NMAX = 1e5 + 5;
ll pr[NMAX], in[NMAX], out[NMAX];

vector<int> g[NMAX];

void dfs1(int u, int p){
    in[u] = 0;
    for(auto & to: g[u]){
        if(to == p)continue;
        dfs1(to, u);
        ll ans = 0;
        if(pr[to] - pr[u] > 0)ans = pr[to] - pr[u];
        in[u] = max(in[u], in[to] + ans); 
    }
}

void dfs2(int u, int p){
    ll mx1 = -1, mx2 = -1;
    for(auto & to : g[u]){
        if(to == p)continue;
        ll ans = 0;
        if(pr[to] - pr[u] > 0)ans = pr[to] - pr[u];
        if(mx1 <= in[to] + ans){
            mx2 = mx1;
            mx1 = in[to] + ans;
        }
        else mx2 = max(mx2, in[to] + ans);
    }
    for(auto & to: g[u]){
        if(to == p)continue;
        ll use = mx1; 
        ll uto = 0, tou = 0;
        if(pr[to] - pr[u] > 0)uto = pr[to] - pr[u];
        if(pr[u] - pr[to] > 0)tou = pr[u] - pr[to];
        if(use == in[to] + uto){
            use = mx2;
        }
        out[to] = max(out[u] + tou, use + tou);
        dfs2(to, u);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> pr[i];
    }
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(0,-1);
    out[0] = 0;
    dfs2(0,-1);
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        cout << max(in[x], out[x]) << endl;
    }
    return 0;
}