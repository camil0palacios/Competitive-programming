#include <bits/stdc++.h>
using namespace std;

int inf = 1000000;

struct nodo{
  int to, w;
  nodo():to(0),w(0){}
  nodo(int _n, int _w): to(_n), w(_w){}
};

typedef vector<vector<nodo>> graph;
typedef vector<bool> vb;
typedef vector<int> vi;

bool operator<(nodo a, nodo b){
  return a.w > b.w;
}

int dijkstra(graph &g, vb used, vi t, vi &id, int n){

  priority_queue<nodo> q;
  q.push(nodo(n,0));
  while(!q.empty()){
    int x = q.top().to;
    int w = q.top().w;
    q.pop();
    if(!used[x]){
      used[x] = true;
      t[x] = w;
      for(auto i : g[x]){
        if(!used[i.to])q.push(nodo(i.to, w + i.w));
      }
    }
  }
  int mmin = inf; // to each node id different
  for(int i = 0; i < id.size(); i++){
    if(id[n] != id[i])mmin = min(mmin, t[i]);
  }
  return (mmin != inf) ? mmin : inf;
}

int res;
double mming;

void comb(graph &g, vector<int>& id, int idx){
  if(idx == g.size()){
    int ans = 0;
    vb used(g.size(),false);
    vi t(g.size(),inf);
    for(int i = 0; i < g.size(); i++){
      int aux = dijkstra(g, used, t, id, i);
      if(aux == inf)return;
      else ans += aux;
    }
    double mmin = ans / (double)g.size();
    if(mmin < mming){
      res = 1;
      mming = mmin;
    }
    else if(mmin == mming)res++;
    return;
  }
  id[idx] = 0;
  comb(g, id, idx + 1);
  id[idx] = 1;
  comb(g, id, idx + 1);
}

int main(){

  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t, c = 1;
  cin >> t;
  while(t--){
    int v,e;
    cin >> v >> e;
    graph g(v, vector<nodo> ());
    for(int i = 0; i < e ; i++){
      int u,v,w;
      cin >> u >> v >> w;
      g[--u].emplace_back(--v,w);
      g[v].emplace_back(u,w);
    }
    vi id(v,0);
    res = 0;
    mming = inf;
    comb(g, id, 0);
    cout << "Case #" << c++ << ": " << res << endl;
  }
  return 0;
}
