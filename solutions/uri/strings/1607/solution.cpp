#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	string s,s1;
	cin>>n;
	while(n--){
		cin>>s>>s1;
		int sum=0;
		for(int i=0; i < s.size(); i++){
			if(s == s1)break;
			if(s[i] <= s1[i]) sum += s1[i] - s[i];
			else sum += ('z'+ 1 - s[i]) + (s1[i] - 'a');
			s[i] = s1[i];
		}
		cout<<sum<<endl;
	}
}