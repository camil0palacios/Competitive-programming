#include <bits/stdc++.h>
using namespace std;


int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,ob;
	cin>>n;
	vector<int> v1(n+1,0),v2(n+1,0);
	for(int i=1; i <= n; i++){
		cin>>ob;
		v1[i] = v1[i-1];
		v2[i] = v2[i-1];
		if(ob)v1[i]++;
		else v2[i]++;
	}
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		if(v2[r]-v2[l-1] > v1[r]-v1[l-1])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}