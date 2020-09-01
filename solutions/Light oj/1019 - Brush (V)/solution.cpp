#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to, w;
    edge(){}
    edge(int _to, int _w): w(_w), to(_to){}
    bool operator<(const edge & e)const{
        return w < e.w;
    }
};

int n, m;
const int inf = 1e7 + 5;
typedef vector<vector<edge> > graph;

int dijkstra(graph & g){
    priority_queue<edge> q;
    vector<int> dis(n, inf);
    q.push(edge(0,0));
    dis[0] = 0;
    while(!q.empty()){
        int v = q.top().to;
        int dist = q.top().w;
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int u = g[v][i].to;
            int w = g[v][i].w;
            if(w + dist < dis[u]){
                dis[u] = w + dist;
                q.push(edge(u,dis[u]));
            }
        }
    } 
    return dis[n-1];
}

void solve(){
    cin >> n >> m;
    graph g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back(edge(v,w));
        g[v].push_back(edge(u,w));
    }
    int ans = dijkstra(g);
    if(ans != inf)cout << ans << endl;
    else cout << "Impossible" << endl; 
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}