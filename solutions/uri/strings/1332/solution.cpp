#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,tmp;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		int a;
		if(s.size() == 5)tmp = 3;
		else{
			if( (s[0] == 'o' && s[1] == 'n') ||  (s[1] == 'n' && s[2] == 'e') || (s[0] == 'o' && s[2] == 'e') )tmp= 1;
			else tmp = 2 ;
		}
		cout<<tmp<<endl;
	}
	return 0;
}