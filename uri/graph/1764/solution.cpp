#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge{
	int u,v,cost;
	Edge(int a, int b, int c): u(a), v(b), cost(c){}
};

bool operator<(Edge a, Edge b){
	return a.cost < b.cost;
}

vector<int> p;

int find(int a){
	return (a == p[a])? a : p[a]=find(p[a]);
}

bool join(int a, int b){
	a =  find(a); b = find(b);
	if(a == b)return true;
	p[a] = b;
	return false;
}

int main(){
	int m,n,x,y,z,sum;
	while(cin>>m>>n && (m+n)){
		vector<Edge> v;
		p.assign(m,0);
		for(int i=0; i < p.size(); i++)p[i]=i;
		while(n--){
			cin>>x>>y>>z;
			v.push_back(Edge(x,y,z));
		}
		sum = 0;
		sort(v.begin(), v.end());
		for(auto &i: v){
			if(!join(i.u,i.v))sum += i.cost;
		}
		cout<<sum<<endl;
	}
	return 0;
}