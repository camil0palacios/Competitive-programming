#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int q,d,p;
	while(cin>>q && q){
		cin>>d>>p;
		int ans  = ((q*p)*d)/(p-q);
		cout<< ans <<" pagina";
		if (ans == 1)cout<<endl;
		else cout<<"s"<<endl;
	}

	return 0;
}