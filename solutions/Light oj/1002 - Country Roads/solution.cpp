#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[505], cost[505];
 
void bfs(int n, int s){
    queue<int> q;
    vector<int> dist(n, 1e9);
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            int d = max(dist[u],cost[u][i]);
            if(d < dist[v]){
                dist[v] = d;
                q.push(v);
            }
        }
    }
    for(auto & i : dist){
        if(i == 1e9)cout << "Impossible" << endl;
        else cout << i << endl;
    }
}
 
void solve(){
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < 505; i++)g[i].clear(), cost[i].clear();
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    cin >> u;
    bfs(n,u);
}
 
 
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}