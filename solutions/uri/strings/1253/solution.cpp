#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n;
	while(n--){
		cin>>s>>k;
		string s1="";
		for(auto &i: s){
			if( i-k < 'A') s1 += 91 - ('A' - (i-k));
			else s1 += i-k;
		}
		cout<<s1<<endl;
	}
	return 0;
}