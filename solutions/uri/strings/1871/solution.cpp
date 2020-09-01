#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	long long n,m;
	while(cin>>n>>m && (n || m)){
		string s =  to_string(n+m),s1;
		for(auto &i : s){
			if(i != '0')s1 += i;
		}
		cout<<s1<<endl;
	}
	return 0;
}