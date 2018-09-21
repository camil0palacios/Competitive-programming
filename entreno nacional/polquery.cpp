#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ll;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> in,low;
set<int> cut;
set<ll> bridge;
int timer;
bool v;

void dfs_b(int n, int &b, ll br){
	if(v)return;
	if(n == b){v = true;return;}
	visited[n] = true;
	for(auto &i : adj[n]){
		ll p(min(i,n),max(i,n));
		if(!visited[i] && p != br)dfs_b(i,b,br);
	}
}

void dfs_c(int n, int &b, int &c){
	if(v)return;
	if(n == b){v = true;return;}
	visited[n] = true;
	for(auto &i : adj[n]){
		if(!visited[i] && i != c)dfs_c(i,b,c);
	}
}

void dfs_bc(int n, int  p = -1){

	visited[n] = true;
	in[n] = low[n] = timer++;
	int children = 0;
	for(auto &i : adj[n]){
		if(i == p)continue;
		if(visited[i]){
			low[n] = min(low[n],in[i]);
		}
		else{
			dfs_bc(i,n);
			low[n] = min(low[n],low[i]);
			if(low[i] > in[n])bridge.insert(ll(min(i,n),max(i,n)));
			if(low[i] >= in[n] && p != -1)cut.insert(n);
			++children;
		}
	}

	if(p == -1 && children > 1)cut.insert(n);
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,e,t,a,b,c,g1,g2;
	cin>>n>>e;
	adj.assign(n,vector<int> ());
	while(e--){
		cin>>a>>b;
		adj[--a].emplace_back(--b);
		adj[b].emplace_back(a);
	}
	visited.assign(n,false);
	in.assign(n,-1);
	low.assign(n,-1);
	timer = 0;
	for(int i = 0; i < n; i++)
		if(!visited[i])dfs_bc(i);
	cin>>e;
	while(e--){
		visited.assign(n,false);
		v = false;
		cin>>t;
		if(t == 1){
			cin>>a>>b>>g1>>g2;g1--;g2--;
			if(bridge.find(ll(min(g1,g2),max(g1,g2))) != bridge.end())
				dfs_b(--a,--b,ll(min(g1,g2),max(g1,g2)));
			else v = true;
		}
		else{
			cin>>a>>b>>c;
			if(cut.find(--c) != cut.end())
				dfs_c(--a,--b,c);
			else v = true;
		}

		if(v)cout<<"da"<<endl;
		else cout<<"ne"<<endl;
	}

	return 0;
}