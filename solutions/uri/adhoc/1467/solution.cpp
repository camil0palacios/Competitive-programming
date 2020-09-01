#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,c;
	char s;
	while(cin>>a>>b>>c){
		if(a == b && b == c)s = '*';
		else if(a != b && a!=c )s = 'A';
		else if(b != a && b!=c )s = 'B';
		else if(c != a && c!=b )s = 'C';

		cout<<s<<endl;
	}
	return 0;
}