#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	if(b==0)return a;
	else return GCD(b,a%b);
}

int main(){

	int t;
	cin>> t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(auto &i: v)cin>>i;
		if(v.size()>1){
			int min = GCD(v[0],v[1]);
			if(v.size()>2){
				for(int i=2; i < v.size(); i++){
					int a = GCD(min,v[i]);
					if(a<min)min=a;
				}
				cout<<min<<endl;
			}
			else cout<< min<<endl;
		}
		else cout<<v[0]<<endl;
	}
	return 0;
}