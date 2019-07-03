#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int NMAX = 100005;
bool mark[NMAX];

int in[NMAX], out[NMAX];

vector<int> g[NMAX];

int dfs1(int u, int p){
    in[u] = (mark[u] ? 0 : -1);
    for(auto & to : g[u]){
        if(to == p)continue;
        int dist = dfs1(to, u);
        if(dist > -1)
            in[u] = max(in[u], dist + 1);
    }
    return in[u];
}

void dfs2(int u, int p){
    int mx1 = -1, mx2 = -1;
    for(auto & to : g[u]){
        if(to == p)continue;
        if(in[to] > mx1){
            mx2 = mx1;
            mx1 = in[to];
        }
        else if(in[to] > mx2){
            mx2 = in[to];
        }
    }
    for(auto & to : g[u]){
        if(to == p)continue;
        int dist = (in[to] == mx1 ? mx2 : mx1);
        if(dist != -1)dist += 2;
        out[to] = dist;
        if(out[u] != -1)out[to] = max(out[to], out[u] + 1);
        if(mark[to])out[to] = max(out[to], 0);
        dfs2(to,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, d, u, v;
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++){
        int x; 
        cin >> x;
        mark[x-1] = 1; 
    }
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(0,-1);
    out[0] = mark[0] ? 0 : -1;
    dfs2(0,-1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (out[i] <= d && in[i] <= d);
    }
    cout << ans << endl;
    return 0;
}