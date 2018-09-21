#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nodes;
vector<int> visited;
int lapiz;

void dfs(int x,int& ini){
	visited[x]=true;
	for(auto &i: nodes[x]){
		if(!visited[i]){
			lapiz+=2;dfs(i,ini);
		}
	}
}

int main(){
	int t,n,v,a,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>v>>a;
		nodes.assign(v,vector<int> ());
		visited.assign(v,false);
		bool matrix[v][v];
		for(int i=0;i < v; i++)
			for(int j=0; j < v ; j++)
				matrix[i][j]=false;
		while(a--){
			cin>>x>>y;
			if(!matrix[x][y]){
				nodes[x].push_back(y);
				nodes[y].push_back(x);
				matrix[x][y] = true;
				matrix[y][x] = true;
			}
		}
		lapiz=0;
		dfs(n,n);
		cout<<lapiz<<endl;
	}
	return 0;
}
