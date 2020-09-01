#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,l;
	string s;
	cin>>n;
	while(n--){
		cin>>l;
		int sum=0,element = 0;
		while(l--){
			cin>>s;
			for(int i = 0 ; i < s.size(); i++){
				sum += (s[i] - 65) + element + i; 
			}
			element++;
		}
		cout<<sum<<endl;
	}
}