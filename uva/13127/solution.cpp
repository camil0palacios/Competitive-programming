#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long inf = 1LL << 60;
typedef pair<int,long long> il;
vector<long long> dist;

struct nodo{
  int n;
  long long w;
  nodo(int a, long long b): n(a), w(b){}
};

bool operator<(nodo a, nodo b){
  return a.w > b.w;
}

void dijkstra(vector<vector<nodo>> &g, vector<bool> &visited, vector<int> &p){
  priority_queue<nodo> q;
  for(auto &i : p)q.push(nodo(i,0));
  while(!q.empty()){
    int n = q.top().n;
    int w = q.top().w;
    q.pop();
    if(!visited[n]){
      visited[n] = true;
      dist[n] = w;
      for(auto &i : g[n])
        if(!visited[i.n])q.push(nodo(i.n, i.w + w));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, b, p;
  while(cin>>n>>m>>b>>p){
    vector<vector<nodo>> g(n);
    for(int i = 0; i < m ; i++){
      int u, v;
      long long w;
      cin>>u>>v>>w;
      g[u].emplace_back(nodo(v,w));
      g[v].emplace_back(nodo(u,w));
    }
    vector<int> banks(b), police(p);
    for(auto &i : banks)cin>>i;
    for(auto &i : police)cin>>i;
    vector<bool> visited(n,false);
    dist.assign(n, inf);
    dijkstra(g,visited,police);
    long long maxv = 0;
    int cont = 0;
    for(auto &i : banks) maxv = max(maxv , dist[i]);
    for(auto &i : banks) cont += (maxv == dist[i]);
    if(maxv == inf)cout << cont << " *" << endl;
    else cout << cont << " " << maxv << endl;
    sort(banks.begin(), banks.end());
    for(auto &i : banks)
      if(dist[i] == maxv){
        cout << i ;
        if(cont - 1)cout << " ";
        else cout << endl;
        cont--;
      }
    }
  return 0;
}
