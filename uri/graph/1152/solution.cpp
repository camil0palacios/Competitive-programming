#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> p;

int Find(int a){
		if(a == p[a])return a;
		else return p[a]=Find(p[a]);
	}

bool Union(int a, int b){
	a = Find(a), b = Find(b);
	if(a == b)return true;
	p[a]=b;
	return false;
}

struct Edge{
	int u,v;
	long long w;
	bool operator<(Edge &other){
		return w < other.w;
	}
};


int main(){
	
	int n,m;
	while(cin >> n >> m && (n + m)){
		vector<Edge> Edges(m);
		for(auto &i: Edges)cin>>i.u>>i.v>>i.w;
		p.resize(m);
		for(int i=0; i < n; i++)p[i]=i;
		long long res=0;
		sort(Edges.begin(), Edges.end());
		for(Edge e: Edges)
			if(Union(e.u,e.v))res += e.w;
		cout<<res<<endl;
	}
	return 0;
}