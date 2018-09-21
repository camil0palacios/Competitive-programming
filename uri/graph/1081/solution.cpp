#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

void dfs(int x,int n){
	visited[x]=true;
	for(auto &i: nodes[x]){
		cout<<string(n,' ');
		if(!visited[i]){
			cout<<x<<"-"<<i<<" pathR(G,"<<i<<')'<<endl;
			dfs(i,n+2);
		}
		else cout<<x<<"-"<<i<<endl;
	}
}

int main(){

	int n,v,e,a,b,k=1;
	cin>>n;
	while(n--){
		cin>>v>>e;
		nodes.assign(v,vector<int> ());
		visited.assign(v,false);
		while(e--){
			cin>>a>>b;
			nodes[a].push_back(b);
		}
		for(auto &i: nodes)sort(i.begin(),i.end());
		cout<<"Caso "<<k<<':';
		for(int i=0; i < v; i++){
			if(!visited[i] && nodes[i].size()>0){
				cout<<endl;
				dfs(i,2);
			}
		}
		k++;
		cout<<endl;
	}
	return 0;
}
