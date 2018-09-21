#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

vector<vector<ii>> adj;
vector<vector<int>> adj1;
vector<bool> visited;
vector<int> table,dp;

struct nodo{
	int n,w;
	nodo(int a, int b): n(a), w(b){}
};

bool operator<(nodo a, nodo b){
	return a.w > b.w;
}

void dijkstra(){

	priority_queue<nodo> q;
	q.push(nodo(0,0));
	while(!q.empty()){
		int n = q.top().n;
		int w = q.top().w;
		q.pop();
		if(!visited[n]){
			visited[n] = true;
			table[n] = w;
			for(auto &i : adj[n])
				if(!visited[i.first])q.push(nodo(i.first,w + i.second));
		}
	}
}

void tree(int n){
	for(int i = 0; i < n; i++)
		for(auto &to: adj[i])
			if(table[i] + to.second == table[to.first])
				adj1[i].emplace_back(to.first);
}

int dfs(int n){
	if(visited[n])return dp[n];
	int ans = 0;
	visited[n] = true;
	for(auto &i: adj1[n])
		ans = ((ans % 1000000007) + dfs(i)%1000000007)%1000000007;
	return dp[n] = ans;
}

int main(){

	int n,m,u,v,w;
	while(cin>>n>>m){
		adj.assign(n,vector<ii> ());
		visited.assign(n,false);
		table.assign(n,0);
		while(m--){
			cin>>u>>v>>w;
			adj[u].emplace_back(ii(v,w));
			adj[v].emplace_back(ii(u,w));
		}
		dijkstra();
		adj1.assign(n,vector<int> ());
		tree(n);
		visited.assign(n,false);
		dp.assign(n,0);
		visited[n-1] = true;
		dp[n-1] = 1;
		cout<<table[n-1]<<" "<<dfs(0)<<endl;
	}

	return 0;
}
