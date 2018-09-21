#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define inf 40000

vector<vector<int>> g;

int floydWarshall(int n, int m){

	vector<vector<int>> p = g;

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				p[i][j] = min(p[i][j],p[i][k] + p[k][j]);
			}

	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
				if(p[i][j] < inf){
					int a = ceil(p[i][j]/(double)m);
					ans = max(ans,a);
				}
			}

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m,a;
	while(cin>>n>>m){
		g.assign(n,vector<int> (n,inf));
		for(int i = 0; i < n ; i++)g[i][i] = 0;
		int i,j,w;
		while(m--){
			cin>>i>>j>>w;
			g[i][j] = g[j][i]= w;
		}
		w = 3,m = inf;
		while(w--){
			cin>>i;
			m = min(m,i);
		}
		cout<<floydWarshall(n,m)<<endl;
	}

	return 0;
}
