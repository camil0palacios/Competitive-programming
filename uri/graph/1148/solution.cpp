#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Nodo{
	int u,h;
	Nodo(int u1,int h1): u(u1),h(h1) {}
};

bool operator <(Nodo a, Nodo b){
	if(a.h < b.h)return false;
	else return true;
}

int main(){

	int n,m;
	while(cin>>n>>m && (n+m)){
		
		vector<vector<int>> nodes(n);
		int edges[n][n];
		int x,y,z;
		for(int i=0; i < n; i++)
			for(int j=0; j < n ; j++)
				edges[i][j] = INT_MAX;

		while(m--){
			cin >> x >> y >> z;
			x--;y--;
			nodes[x].push_back(y);
			edges[x][y] = z;	
			if(edges[y][x] != INT_MAX){
				edges[x][y] = 0;
				edges[y][x] = 0;
			}
		}

		int k,a,b;
		cin>>k;
		while(k--){
			cin>>a>>b; //dijkstra
			a--;b--;
			vector<int> table(n,INT_MAX);
			vector<bool> visited(n,false);
			priority_queue<Nodo> q;
			Nodo aux(a,0);
			q.push(aux);
			while(q.size()){
				int actual = q.top().u;
				int suma = q.top().h;
				q.pop();
				if(!visited[actual]){
					visited[actual] = true;
					for(auto &i: nodes[actual]){
						if(!visited[i]){
							if(suma + edges[actual][i] < table[i]){
								Nodo newnode(i , suma + edges[actual][i]);
								q.push(newnode);
								table[i] = suma + edges[actual][i] ;
							}
						}
					}
				}			
			}
			if(table[b] == INT_MAX)cout<<"Nao e possivel entregar a carta"<<endl;
			else cout<<table[b]<<endl;
		}
		cout<<endl;
	}
	return 0;
}