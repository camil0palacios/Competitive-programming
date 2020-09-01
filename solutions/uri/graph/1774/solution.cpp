#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout<<x<<endl;
using namespace std;

vector<int> p;

int find(int n){
	if(n == p[n])return n ;
	else return p[n] = find(p[n]);
}

bool join(int a, int b){
	a = find(a), b = find(b);
	if(a == b)return false;
	p[a] = b;
	return true;
}


struct edge{
	int u,v,w;
	bool operator<(edge &other){
		return w < other.w;
	}	
};

int main(){
	
	int r,c,sum=0;
	cin>>r>>c;
	p.assign(r,0);
	for(int i=0; i < r; i++)p[i]=i;
	vector<edge> vec(c);
	for(auto &i : vec)cin>>i.u>>i.v>>i.w;
	sort(vec.begin(),vec.end());
	for(edge e : vec)
		if(join(e.u-1,e.v-1))sum += e.w;

	cout<<sum<<endl;
	return 0;
	
}