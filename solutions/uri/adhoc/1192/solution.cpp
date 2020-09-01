#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s;
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		if(s[1] >= 'A' && s[1] <= 'Z'){
			if(s[0] == s[2])cout<<(s[0]-'0')*(s[2]-'0')<<endl;
			else cout<<(s[2]-'0')-(s[0]-'0')<<endl;
		}
		else{
			if(s[0] == s[2])cout<<(s[0]-'0')*(s[2]-'0')<<endl;
			else cout<<(s[0]-'0')+(s[2]-'0')<<endl;
		}
	}
	return 0;
}