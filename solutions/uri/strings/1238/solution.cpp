#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s1,s2;
	cin>>n;
	while(n--){
		cin>>s1>>s2;
		string s;
		int c1=0,c2=0;
		while(c1 < s1.size() || c2 < s2.size()){
			if(c1 < s1.size())s += s1[c1];
			if(c2 < s2.size())s += s2[c2];
			c1++;c2++;
		}
		cout<<s<<endl;
	}
	return 0;
}