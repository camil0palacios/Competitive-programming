#include <bits/stdc++.h>
using namespace std;

#define ss second
#define ff first

int inf = 20000000;
typedef pair<int, int> ii;
typedef vector<vector<ii>> graph;
vector<bool> used;
vector<int> dist;
set<ii> block;

bool operator<(ii a, ii b){
    return a.ss > b.ss;
}

void dijkstra(graph & g, int n, int s){
    priority_queue<ii> q;
    dist.assign(g.size(), inf);
    q.push({n,0});
    dist[n] = 0;
    while(!q.empty()){
        n = q.top().ff;
        int w = q.top().ss;
        q.pop();
        for(auto & i : g[n]){
            if(!block.count({n,i.ff})){
                if(w + i.ss < dist[i.ff]){
                    dist[i.ff] = w + i.ss;
                    q.push({i.ff, i.ss + w});
                }
            }
        }
    }
}

void dfs(graph & g, int n){
    used[n] = 1;
    for(auto & i : g[n]){
        bool f = 0;
        if(dist[i.ff] + i.ss == dist[n]){
            block.insert({i.ff, n});
            f = 1;
        }
        if(!used[i.ff] && f){
            dfs(g, i.ff);
        }
    }
}

int main(){

    int n, m, s, d, u, v, c;
    while(cin >> n >> m && n && m){
        cin >> s >> d;
        graph g(n), t(n);
        for(int i = 0 ; i < m; i++){
            cin >> u >> v >> c;
            g[u].emplace_back(v,c);
            t[v].emplace_back(u,c);
        }
        block.clear();
        dijkstra(g, s, d);
        used.assign(n, 0);
        dfs(t, d);
        dijkstra(g, s, d);
        if(dist[d] != inf)cout << dist[d] << endl;
        else cout << -1 << endl;

    }
    return 0;
}