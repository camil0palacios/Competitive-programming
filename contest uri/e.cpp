#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<string,string> ii;

map<string,string> p;

string find(string a){
	return (a == p[a])? a : p[a] = find(p[a]);
}

void join(string a, string b){
	a = find(a); b = find(b);
	if(a == b)return;
	p[b] = a;
}

int main(){
	
	int n,m;
	cin >> n >> m;
	string p1,p2,r;
	set<string> pp;
	while(m --){
		cin >> p1 >> r >> p2;
		int c1 = pp.count(p1) , c2 = pp.count(p2);
		if(c1 > 0){
			pp.insert(p2);
			p.insert(ii(p2,p2));
			join(p1,p2);
		}
		else if(c2 > 0){
			pp.insert(p1);
			p.insert(ii(p1,p1));
			join(p2,p1);
		}
		else{
			pp.insert(p1);
			pp.insert(p2);
			p.insert(ii(p1,p1));
			p.insert(ii(p2,p2));
			join(p1,p2);
		}
	}
	pp.clear();
	for(auto i: p){
		string a = find(i.first);
		if(pp.count(a) == 0)pp.insert(a);
	}
	cout << pp.size() <<endl;

	return 0;
}