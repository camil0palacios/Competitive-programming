#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

unordered_map<char,char> p;

char find(char a){
	return (a == p[a]) ? a : p[a]=find(p[a]);
}

void joint(char a, char b){
	a = find(a);b = find(b);
	if(a > b)p[a] = b;
	else p[b]=a;
}

int main(){
	int n,v,e,k=1;
	char a,b;
	cin>>n;
	while(n--){
		cin>>v>>e;
		map<char,vector<char>> c;
		p.clear();
		for(char i = 'a'; i < ('a'+ v); ++i)p[i]=i;
		while(e--){
			cin>>a>>b;
			joint(a,b);
		}
		for(char i = 'a'; i < ('a'+v); ++i)
			c[find(i)].push_back(i);

		int cont=0;
		cout<<"Case #"<<k<<':'<<endl;
		for(auto &i: c){
			for(auto &j: i.second)
				cout<<j<<',';
			cout<<endl;
		}
		cout<<c.size()<<" connected components"<<endl<<endl;
		k++;
	}
	return 0;
}