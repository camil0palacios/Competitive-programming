#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,a;
	cin>>n;
	vector<int> v = {20,10,5,2,1};
	while(n--){
		cin>>a;
		int cont=0;
		for(auto &i: v){
			int b = a/i;
			if(b != 0){
				cont+=b;
			}
			a = a % i; 
		}
		cout<<cont<<endl;
	}
	return 0;
}