#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,d;
	cin>>n;
	while(n--){
		cin>>k;
		while(k--){
			cin>>d;
			if(d == 1)cout<<"Rolien"<<endl;
			if(d == 2)cout<<"Naej"<<endl;
			if(d == 3)cout<<"Elehcim"<<endl;
			if(d == 4)cout<<"Odranoel"<<endl;
		}
	}
	return 0;
}