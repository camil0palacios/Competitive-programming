#include <bits/stdc++.h>
using namespace std;

int main(){
	
	vector<bool> criba(10000,true);
	for(int i=2; i < 10000; i++){
		if(criba[i])
		for(int j=2; j*i <10000; j++)
			criba[i*j]=false;
	}criba[0]=false;criba[1]=false;
	int t;
	cin>> t;
	while(t--){
		int n;
		bool prim=false;
		cin>>n;
		string s = to_string(n);
		sort(s.begin(),s.end());
		do{
			if(s[0] != '0'){
				if(criba[stoi(s)]){prim=true;cout<<"YES"<<endl;break;}
			}
		}while(next_permutation(s.begin(),s.end()));
		if(!prim)cout<<"NO"<<endl;
	}
	return 0;
}