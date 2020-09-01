#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

bool operator<(ii &a, ii &b){
	return a.first < b.first;
}

int main(){
	
	int n;
	while(cin>>n && n){
		vector<ii> p(n);
		int tmp;
		for(int i = 0; i < n; i++){
			cin>>tmp;
			p[i] = ii(tmp,i);
		}
		sort(p.begin(),p.end());
		if(p.size() > 1)cout<< p[p.size()-2].second + 1<<endl;
		else cout<< 1 << endl;

	}

	return 0;
}