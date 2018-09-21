#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<bool> criba(10000000,true);
	criba[0]=false;
	criba[1]=false;
	for(int i=2; i < 10000000; i++){
		if(criba[i])
			for(int j=2; j*i < 10000000; j++)
				criba[i*j]=false;
	}

	int n;
	string s;
	while(cin>>n>>s){
		bool v=false;
		for(int i=0; i <= s.size()-n; i+=n){
			string substr = s.substr(i,n);
			if(!criba[stoi(substr)]){v=true;break;}
		}
		if(v)cout<<":("<<'\n';
		else cout<<":)"<<'\n';
	}

	return 0;
}
