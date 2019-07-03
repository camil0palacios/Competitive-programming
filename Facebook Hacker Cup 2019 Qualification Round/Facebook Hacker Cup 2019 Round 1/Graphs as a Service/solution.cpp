#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to, w;
    edge(int _to, int _w): to(_to), w(_w){}
    bool operator<(const edge & e)const{
        return w > e.w;
    }
};

struct query{
    int u, v, w;
    query(int _u, int _v, int _w):
        u(_u), v(_v), w(_w){}
};

typedef vector<vector<edge>> graph;

const int inf = 100005;

int dijkstra(graph & g, int s, int f){
    vector<int> dist(g.size(), inf);
    priority_queue<edge> q;
    q.push(edge(s,0));
    dist[s] = 0;
    while(!q.empty()){
        int u = q.top().to;
        int cost = q.top().w;
        q.pop();
        if(cost != dist[u])continue;
        for(auto & ed : g[u]){
            int v = ed.to;
            int w = ed.w;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push(edge(v, dist[v]));
            }
        }
    }
    return dist[f];
}

void floyd(vector<vector<int>> & dp){
    int n = dp.size();
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int n, m, ans = 0;
        cin >> n >> m;
        graph g(n);
        vector<vector<int>> dp(n, vector<int>(n, inf));
        vector<query> q;
        bool flag = 1;
        for(int i = 0; i < m; i++){
            int u, v, z;
            cin >> u >> v >> z;
            u--, v--;
            int res = dijkstra(g,u,v);
            if(res == inf || res >= z){    
                g[u].emplace_back(v,z);
                g[v].emplace_back(u,z);
                dp[u][v] = z;
                dp[v][u] = z;
                ans++;
            }else{ 
                flag = 0;
            }
            q.emplace_back(query(u,v,z));
        }
        floyd(dp);
        for(int i = 0; i < m; i++){
            int u = q[i].u, v = q[i].v, z = q[i].w;
            flag &= (dp[u][v] == z);
        }
        cout << "Case #" << cs << ": ";
        if(flag){
            cout << ans << endl;
            set<pair<int,int>> edges;
            for(int i = 0; i < g.size(); i++){
                for(int j = 0; j < g[i].size(); j++){
                    if(!edges.count({g[i][j].to+1,i+1})){
                        cout << i + 1 << " " << g[i][j].to + 1 << " " << g[i][j].w << endl;
                        edges.insert({i+1,g[i][j].to+1});
                    }
                }
            }
        }else cout << "Impossible" << endl;
    }
    return 0;
}