#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n;
	cin>>n;
	cin.ignore();
	while(n--){
		
		getline(cin,s);
		for(auto &i:s){
			if(i >='A' && i <= 'Z' || i >= 'a' && i <= 'z')
				i += 3;
		}
		reverse(s.begin(),s.end());
		for(int i=s.size()/2; i < s.size(); i++){
				s[i] -= 1;
		}
		cout<<s<<endl;
	}
	return 0;
}