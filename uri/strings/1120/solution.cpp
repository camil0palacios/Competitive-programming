#include <bits/stdc++.h>
using namespace std;

int main(){
	char n;
	string s;
	while(true){
		cin>>n>>s;
		if(n == '0')break;
		string s1 = "";
		for(auto &i :s)
			if(i != n)s1+=i;

		while(s1[0] == '0'){
			if(s1.size()==1)break;
			s1.erase(0,1);
		}
		if(s1.size() == 0)cout<<0<<endl;
		else cout<<s1<<endl;
	}
	return 0;
}