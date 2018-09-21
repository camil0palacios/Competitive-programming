#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,x,y,q,s;
	cin>>n>>m;
	vector<vector<int>> graph(n);
	while(m--){
		cin>>x>>y;
		x--;y--;
		graph[x].push_back(y);
	}
	cin>>q;
	while(q--){
		unordered_set<int> exp;
		unordered_set<int> visited;
		queue<int> q;
		cin>>s;
		s--;
		int cont=0;
		q.push(s);
		while(q.size()){
			int x = q.front();q.pop();
			exp.insert(x);
			cont++;
			for(auto &i: graph[x]){
				if(exp.find(i) == exp.end() && visited.find(i) == exp.end()){
					q.push(i);
					visited.insert(i);
				}
			}
		} 
		cont--;
		cout<<cont<<endl;
	}
	return 0;
}