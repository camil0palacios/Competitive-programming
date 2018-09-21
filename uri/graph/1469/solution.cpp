#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> age;
vector<int> pos;
vector<int> h;

int old;

int dfs(int node){
	visited[node] = true;
	if(graph[node].empty()){return age[pos[node]] ;}
	int res = INT_MAX;
	for(auto &i: graph[node]){
		if(!visited[i])res = min(age[pos[node]],dfs(i));
	}
	return res;
}

int main(){
	
	int n,m,i,x,y;
	char in;
	while(cin>>n>>m>>i){

		age.assign(n,0);
		pos.assign(n,0);
		h.assign(n,0);int tmp;
		for(int i=0; i < n ; i++){
			cin>>tmp;
			age[i]=tmp;
			pos[i] = i;
			h[i] = i;
		}
		graph.assign(n,vector<int>());
		while(m--){
			cin>>x>>y;
			graph[--y].emplace_back(--x);
		}

		while(i--){
			cin>>in>>x;
			if(in == 'T'){
				cin>>y;
				swap(h[x-1],h[y-1]);
				int h1 = h[x-1], h2 = h[y-1];
				swap(pos[h1],pos[h2]);
			}
			else{
				x--;
				int old = INT_MAX;
				visited.assign(n,false);
				for(auto &i : graph[h[x]]){
					if(!visited[i])old = min(old,dfs(i));
				}

				if(old == INT_MAX)cout<<'*'<<endl;
				else cout<<old<<endl;
			}

		}

	}

	return 0;
}