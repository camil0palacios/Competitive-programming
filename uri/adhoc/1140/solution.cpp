#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	
	string s;
	while(getline(cin,s) && s[0] != '*'){
		char c = tolower(s[0]);
		bool res = true;
		for(int i = 1; i < s.size() - 1; i++){
			if(s[i] == ' ' && tolower(s[i+1]) != c)res=false;
		}
		if(res)cout<<'Y'<<endl;
		else cout<<'N'<<endl;
	}

	return 0;
}