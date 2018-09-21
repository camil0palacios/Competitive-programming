#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long inf = 1LL << 60;

struct edge{
	int to, w, id;
	edge(int a, int b, int c): to(a), w(b), id(c){}
};

typedef vector<vector<edge>> graph;

vector<bool> vi;
vector<int> path;

bool findpath(graph &g, int node, int pid, int t){
	if(node == t)return true;
	for(auto &e : g[node]){
		if(!vi[e.to] && e.id != pid){
			vi[e.to] = true;
			if(findpath(g,e.to,e.id,t)){
				path.push_back(e.id);
				return true;
			}
		}
	}
	return false;
}

vector<int> in,low,bridges;
int timer;

bool findbridges(graph &g, int node, int pid, int proid, int t){
	vi[node] = true;
	in[node] = low[node] = timer++;
	int c = (node == t);
	for(auto &e : g[node]){
		if(e.id == pid || e.id == proid)continue;
		if(in[e.to] != -1) low[node] = min(low[node], in[e.to]);
		else{
			int tmp = findbridges(g,e.to,e.id,proid,t);
			c |= tmp;
			low[node] = min(low[node],low[e.to]);
			if(in[e.to] == low[e.to] && tmp)bridges.push_back(e.id);
		}
	}
	return c;
}


int main(){
	
	int n,m,a,b,u,v,w;
	cin>>n>>m;
	cin>>a>>b;
	graph g(n);
	vi.assign(n,false);
	vector<int> cost(m);
	for(int i = 0; i < m; i++){
		cin>>u>>v>>w;
		u--;v--;
		g[u].emplace_back(v,w,i);
		g[v].emplace_back(u,w,i);
		cost[i] = w;
	}
	a--;b--;
	vi[a]=true;
	findpath(g,a,-1,b);

	if(!vi[b]){
		cout<< 0 << endl << 0 << endl;
		return 0;
	}

	long long ans = inf;
	vector<int> res;
	for(auto fore : path){
		in.assign(n,-1);
		low.assign(n,-1);
		bridges.clear();
		timer = 0;
		if(!findbridges(g,a,-1,fore,b)){
			if(ans > cost[fore] ){
				ans = cost[fore];
				res.clear();
				res.push_back(fore);
			}
		}
		else{
			for(auto id: bridges){
				long long tmp = cost[fore] + cost[id];
				if(tmp < ans){
					ans = tmp;
					res.clear();
					res.push_back(fore);
					res.push_back(id);
				}
			}
		}

	}

	if(res.size() == 0)cout << -1 << endl;
	else {
		cout << ans << endl;
		cout << res.size() << endl;
		for(auto e: res)
			cout<< e + 1<< " ";
		cout<<endl;
	}

	return 0;
}