#include <bits/stdc++.h>
using namespace std;

int josephus(int n,int k){
	if(n==1)return 1;
	else return (josephus(n-1,k)+k-1)% n + 1;
}

int main(){
	
	int nc,n,k,cont=1;
	cin>>nc;
	while(nc--){
		cin>>n>>k;
		cout<<"Case "<<cont<<": "<<josephus(n,k)<<endl;
		cont++;
	}
	return 0;
}