#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	long long x;
	string s;
	while(n--){
		cin>>x;
		if(x%2 == 0)s = "EVEN";
		else s = "ODD";
		if(x > 0)s += " POSITIVE";
		else if(x < 0)s += " NEGATIVE";
		else s = "NULL";
		cout<<s<<endl;
	}

	return 0;
}
