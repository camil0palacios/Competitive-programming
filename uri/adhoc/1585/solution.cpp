#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int area(int d,int h){
	return (d*h)/2;
}

int main(){
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,d,h;
	cin>>n;
	while(n--){
		cin>>d>>h;
		cout<<area(d,h)<<" cm2"<<endl;
	}

	return 0;
}