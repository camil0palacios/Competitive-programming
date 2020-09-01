#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct edge{
    int to;
    long long w;
    edge(){}
    edge(int _to, int _w): to(_to), w(_w){}
};

struct node{
    int u, k;
    long long cost;
    node(){}
    node(int _u, int _k, long long _cost): u(_u), k(_k), cost(_cost){}
    bool operator<(const node & o)const{
        if(k == o.k){
            return cost > o.cost;
        }
        return k > o.k;
    }
};

typedef vector<vector<edge>> graph;
int N, M, K;
long long inf = 1LL << 55;

long long dijkstra(graph & g){
    priority_queue<node> q;
    q.push(node(0,1,0));
    vector<long long> dist(N, inf);
    while(!q.empty()){
        int u = q.top().u;
        int k = q.top().k;
        long long cost = q.top().cost;
        q.pop();
        //cout << u << endl;
        if(cost < dist[u]){
            dist[u] = cost;
            for(auto & v : g[u]){
                int to = v.to;
                long long n_cost = v.w + cost;
                if(k + 1 <= K){
                    q.push(node(to, k+1, n_cost));
                }
            }
        }
    }
    return dist[N-1];
}

void solve(){
    int u, v;
    long long w;
    cin >> N >> M >> K;
    graph g(N);
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
    }
    long long ans = dijkstra(g);
    cout << (ans >= inf ? -1 : ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs =  1; cs <= t; cs++){
        solve();
    }
    return 0;
}