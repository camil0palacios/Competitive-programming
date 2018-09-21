#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

vector<vector<int>> g;
vector<bool> visited;
vector<int> in,low;
vector<ii> ans;
int cont;

void dfs(int n, int p = -1){
	
	visited[n] = true;
	in[n] = low[n] = cont++;
	for(auto &i: g[n]){
		if(i == p)continue;
		if(visited[i]){
			low[n] = min(low[n],in[i]);
		}
		else{
			dfs(i,n);
			low[n] = min(low[n],low[i]);
			if(low[i] > in[n]){
				ans.emplace_back(ii(min(i,n),max(i,n)));
			}
		}
	}
}

void find_birdges(){

	visited.assign(g.size(),false);
	in.assign(g.size(),-1);
	low.assign(g.size(),-1);
	cont = 0;
	for(int i = 0; i < g.size(); i++){
		if(!visited[i])dfs(i);
	}
	cout<<ans.size()<<" critical links"<<endl;
	sort(ans.begin(), ans.end());
	for(auto &i: ans)
		cout<<i.first<<" - "<<i.second<<endl;
	cout<<endl;
}

int main(){

	int n,u,e,v;
	while(cin>>n){
		g.assign(n,vector<int> ());
		ans.clear();
		while(n--){
			scanf("%d (%d)",&u,&e);
			while(e--){
				cin>>v;
				g[u].emplace_back(v);
			}
		}
		find_birdges();
	}

	return 0;
}