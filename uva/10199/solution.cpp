#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

map<string,vector<string>> adj;
vector<string> city;
set<string> visited;
map<string,int> in,low;
set<string> ans;
int timer,k;

void dfs(string s, string p = ""){
	visited.insert(s);
	in[s] = low[s] = timer++;
	int children = 0;
	for(auto &i : adj[s]){
		if(i == p)continue;
		if(visited.find(i) != visited.end()){
			low[s] = min(low[s],in[i]);
		}
		else{
			dfs(i,s);
			low[s] = min(low[s], low[i]);
			if(low[i] >= in[s] && p != "")ans.insert(s);
			++children;
		}
	}
	if(p == "" && children > 1)
		ans.insert(s);
}

void findcutpoints(){
	timer = 0;
	visited.clear();
	in.clear();
	low.clear();
	ans.clear();
	for(int i = 0; i < city.size(); i++){
		if(visited.count(city[i]) == 0)
			dfs(city[i]);
	}
	cout<<"City map #"<<k<<": "<<ans.size()<<" camera(s) found"<<endl;
	for(auto &i: ans)
		cout<<i<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;
	string u,v;
	bool flag = false;
	k = 0;
	while(cin>>n && n){
		k++;
		adj.clear();
		city.clear();
		if(flag)cout<<endl;
		while(n--){
			cin>>u;
			city.emplace_back(u);
		}
		cin>>m;
		while(m--){
			cin>>u>>v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		findcutpoints();
		flag = true;
	}

	return 0;
}
