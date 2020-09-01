#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

int main(){
	
	vector<int> x(5);
	vector<int> y(5);
	for(auto &i: x)cin>>i;
	for(auto &i: y)cin>>i;
	bool res = true;
	for(int i = 0; i < 5; i++){
		if(x[i] == y[i])res=false;
	}

	if(res){cout << 'Y' << endl;}
	else cout << 'N' <<endl;

	return 0;
}