#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


typedef pair<int,int> ii;

int main(){
	
	int n,m;
	char l;
	while(cin>>n){
		unordered_map<int,int> d;
		unordered_map<int,int> e;
		while(n--){
			cin >> m >> l;
			if( l  == 'D')
				if(d.find(m) == d.end())d.insert(ii(m,1));
				else ++d[m];
			else if(e.find(m) == e.end())e.insert(ii(m,1));
			else ++e[m];	
		}
		int cont = 0 ;
		for(auto &i: d){
			if(e.find(i.first) != e.end())
				cont += (i.second == e[i.first]) ? i.second : (i.second < e[i.first])? i.second : e[i.first]; 
		}
		cout << cont << endl;
	}
	return 0;
}