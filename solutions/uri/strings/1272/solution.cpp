#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	string s;
	cin>>n;
	cin.ignore();
	while(n--){
		getline(cin,s);
		string s1;
		if((s[0] >= 'a' && s[0]<= 'z') || (s[0] >= 'A' && s[0]<= 'Z'))s1+=s[0];
		for(int i=1; i < s.size() ; i++){
			if(s[i-1] == ' ' && (s[i] >= 'a' && s[i]<= 'z') || (s[i] >= 'A' && s[i]<= 'Z'))
				s1 += s[i];
		}
		cout << s1 <<endl;
	}
	return 0;
}