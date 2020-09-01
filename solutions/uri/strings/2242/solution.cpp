#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,s1;
	cin>>s;
	for(auto &i : s){
		if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
			s1 += i; 
		}
	}
	char n = 'S';
	for(int i=0,j = s1.size()-1; i <= j; i++,j--){
		if(s1[i] !=  s1[j]) n = 'N';
	}
	cout<<n<<endl;
	return 0;
}