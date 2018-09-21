#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> edges;
vector<int> table;
vector<bool> visited;

struct nodo{
	int n,value;
	nodo(int a, int b){ n = a; value = b;}
};

bool operator<(nodo a, nodo b){
	if(a.value < b.value)return false;
	return true;
}

void Dijkstra(int c,int k){

	priority_queue<nodo> q;
	q.push(nodo(k,0));
	while(q.top().n != c-1 && q.size()){
		int x = q.top().n;
		int s = q.top().value;
		q.pop();
		if(!visited[x]){
			visited[x] = true;
			if( x < c-1){
				if(!visited[x+1]){
					if(s + edges[x][x+1] < table[x+1]){
						q.push(nodo(x+1,s + edges[x][x+1]));
						table[x+1] = s + edges[x][x+1];
					}
				}
			}
			else{
				for(auto &i: graph[x]){
					if(!visited[i]){
						if(s + edges[x][i] < table[i]){
							q.push(nodo(i, s + edges[x][i]));
							table[i] = s + edges[x][i];
						}
					}
				}
			}
		}
	}
	cout<<q.top().value<<endl;
}

int main(){
	
	int n,m,c,k,u,v,p;
	while(cin>>n>>m>>c>>k && (n+m+c+k)){
		graph.assign(n,vector<int>());
		edges.assign(n,vector<int>(n));
		table.assign(n,INT_MAX);
		visited.assign(n,false);
		while(m--){
			cin>>u>>v>>p;
			graph[u].push_back(v);
			graph[v].push_back(u);
			edges[u][v] = p;
			edges[v][u] = p;
		}
		Dijkstra(c,k);
	}
	return 0;
}