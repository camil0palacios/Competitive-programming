#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> nodes;
vector<int> visited;
bool loop;

void dfs(int x){
	visited[x] = 1;
	if(loop)return;
	for(auto &i: nodes[x]){
		if(visited[i] == 0)dfs(i);
		else if(visited[i] == 1){loop = true;return;}
	}
	visited[x]=2;
}

int main(){

	int t,n,m,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		nodes.assign(n,vector<int> ());
		visited.assign(n,0);
		while(m--){
			cin>>a>>b;
			nodes[--a].push_back(--b);
		}
		loop = false;
		for(int i=0; i < n; i++){
			if(!visited[i])dfs(i);
			if(loop)break;
		}
		if(loop)cout<<"SIM"<<endl;
		else cout<<"NAO"<<endl;
	}
	return 0;
}
