#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

struct edge{
    int to, w;
    edge(){}
    edge(int _to, int _w): to(_to), w(_w){}
    bool operator<(const edge & o)const{
        return w > o.w;
    }    
};

typedef vector< vector<edge> > graph;

vector<int> dijkstra(graph & g, int s){
    vector<int> d(g.size(), inf);
    priority_queue<edge> q;
    q.push(edge(s,0));
    d[s] = 0;
    while(!q.empty()){
        int u = q.top().to;
        int dist = q.top().w;
        q.pop();
        if(dist > d[u])continue;
        for(int i = 0; i < g[u].size(); i++){
            int to = g[u][i].to;
            int w = g[u][i].w;
            if(dist + w < d[to]){
                d[to] = dist + w;
                q.push(edge(to,d[to]));
            }
        }
    }
    return d;
}

void solve(){
    int n, m, s, t, p;
    cin >> n >> m >> s >> t >> p;
    graph g1(n), g2(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g1[u].push_back(edge(v,w));
        g2[v].push_back(edge(u,w));
    }
    s--, t--;
    vector<int> st = dijkstra(g1,s);
    vector<int> ts = dijkstra(g2,t);
    int ans = -1;
    for(int i = 0; i < g1.size(); i++){
        for(int j = 0; j < g1[i].size(); j++){
            int u = i, v = g1[i][j].to, w = g1[i][j].w;
            if(st[u] + ts[v] + w <= p){
                ans = max(ans, w);
            }
        }
    }
    cout << ans << endl;
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