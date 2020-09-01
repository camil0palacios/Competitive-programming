#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	string s;
	while(n--){
		int cont=0;
		cin>>s;
		if(s.size() > 3)
			for(int i=0; i <= s.size()-4; i++){
				if(s.substr(i,4) == "love")
					cont++;
			}
		cout<<cont<<endl;
	}
	return 0;
}