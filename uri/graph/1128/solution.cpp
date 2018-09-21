#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

/**
	kosaraju's algorithm
*/

vector<vector<int>> graph;
vector<vector<int>> r_graph;
vector<int> visited;
stack<int> s;
int cont;

void dfs(int n){
	visited[n] = true;
	for(auto &i: r_graph[n])
		if(!visited[i])dfs(i);
}

void dfs_stack(int n){
	visited[n] = true;
	for(auto &i: graph[n])
		if(!visited[i])dfs_stack(i);
	s.push(n);
}

void kosaraju(int n){
	visited.assign(n,false);
	for(int i=0; i < graph.size(); i++){
		if(!visited[i])dfs_stack(i);
	}
	visited.assign(n,false);
	cont = 0;
	while(s.size()){
		int x = s.top();
		s.pop();
		if(!visited[x]){
			cont++;
			dfs(x);
		}
	}
}

int main(){
	int n,m,v,w,p;
	while(cin>>n>>m && (n + m)){
		graph.assign(n,vector<int> ());
		r_graph.assign(n,vector<int> ());
		while(m--){
			cin>>v>>w>>p;v--;w--;
			graph[v].push_back(w);
			r_graph[w].push_back(v);
			if(p == 2){
				graph[w].push_back(v);
				r_graph[v].push_back(w);
			}
		}
		kosaraju(n);
		if(cont == 1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
