#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<string,string> si;

map<string,vector<si>> graph;
map<string, bool> visited;

struct node{
	string s,s1;
	int cost;
	node(string ss, string ss1, int a){ s = ss; s1 = ss1; cost = a;}
};

bool operator<(node a, node b){
	return a.cost > b.cost;
}

int Dijkstra(string o, string d){

	set<si> con;
	priority_queue<node> q;
	q.push(node(o," ",0));
	while(!q.empty() && q.top().s != d){
		string s = q.top().s;
		string w = q.top().s1;
		int a =  q.top().cost;
		q.pop();
		if(con.count(si(s,w)) == 0){
			con.insert(si(s,w));
			for(auto i: graph[s]){
				if(con.count(si(i.first,w)) == 0 && i.second[0] != w[0]){
					q.push(node(i.first,i.second, a + i.second.size()));
				}
			}
		}
	}
	return (q.size() > 0 ) ? q.top().cost : -1;

}

int main(){
	int m;
	string o,d,i1,i2,p;
	while(cin>>m && m){
		cin>>o>>d;
		graph.clear();
		visited.clear();
		while(m--){
			cin>>i1>>i2>>p;
			if(graph.find(i1) ==  graph.end())graph.insert({i1,vector<si>()});
			graph[i1].push_back(si(i2,p));
			if(graph.find(i2) ==  graph.end())graph.insert({i2,vector<si>()});
			graph[i2].push_back(si(i1,p));
		}
		int res = Dijkstra(o,d);
		if(res != -1)cout<<res<<endl;
		else cout<<"impossivel"<<endl;
	}

	return 0;
}