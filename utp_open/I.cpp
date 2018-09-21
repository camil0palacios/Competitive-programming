#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		int suma=0;
		while(a){suma+=a&1; a>>=1;}
		while(b){suma+=b&1; b>>=1;}
		cout<<suma<<endl;
	}

	return 0;
}