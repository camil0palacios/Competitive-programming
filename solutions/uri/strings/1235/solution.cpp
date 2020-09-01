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
		for(int i = s.size()/2-1; i >= 0; i--)s1 += s[i];
		for(int i = s.size()-1;i  >= s.size()/2 ; i--)s1 += s[i];
		cout<< s1 <<endl;
	}
	return 0;
}