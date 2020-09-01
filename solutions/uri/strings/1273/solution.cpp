#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<" "<< x <<" ";
#define endl '\n'

int main(){
	
	int n;
	bool p = true;
	while(true){
		cin>>n;
		if(n == 0)break;
		vector<string> v(n);
		int max=0;
		for(auto &i : v){
			cin>> i;
			if(i.size() > max)max = i.size();
		}
		if(!p)cout<<endl;
		for(auto &i : v){
			int n= max-i.size();
			cout<<string(n,' ')<<i<<endl;
		}
		p = false;
	}

	return 0;
}