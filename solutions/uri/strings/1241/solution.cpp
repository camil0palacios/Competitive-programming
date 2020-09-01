#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	string a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(a .size() >=  b.size()){
			if(a.substr(a.size()-b.size(),b.size()) == b)cout<<"encaixa"<<endl;
			else cout<<"nao encaixa"<<endl;
		}
		else cout<<"nao encaixa"<<endl;
	}
	return 0;
}