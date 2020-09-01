#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> in,low;
int timer,ans;

void dfs(int n, int p = -1){
	 visited[n] = true;
	 in[n] = low[n] = ++timer;
	 for(auto &to : adj[n]){
	 	if(to == p)continue;
	 	if(visited[to])low[n] = min(low[n], in[to]);
	 	else{
	 		dfs(to,n);
	 		low[n] = min(low[n], low[to]);
	 		if(low[to] > in[n])ans++;
	 	}
	 }
}

void find_bridges(int n){
	timer = 0;
	ans = 0;
	in.assign(n,-1);
	low.assign(n,-1);
	visited.assign(n,false);
	for(int i = 0; i < n; i++)
		if(!visited[i])dfs(i);
	cout<<ans<<endl;
}

int main(){
	
	int n,m,u,v;
	while(cin>>n>>m){
		adj.assign(n,vector<int>());
		while(m--){
			cin>>u>>v;u--;v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);

		}
		find_bridges(n);
	}

	return 0;
}