#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	string s;
	while(true){
		cin>>n;
		if(n==0)break;
		cin>>s;
		char dir='N';
		for(auto &i:s){
			if(dir == 'N' && i == 'D')dir='L';
			else if(dir == 'N' && i == 'E')dir='O';
			else if(dir == 'L' && i == 'D')dir='S';
			else if(dir == 'L' && i == 'E')dir='N';
			else if(dir == 'S' && i == 'D')dir='O';
			else if(dir == 'S' && i == 'E')dir='L';
			else if(dir == 'O' && i == 'D')dir='N';
			else if(dir == 'O' && i == 'E')dir='S';
		}
		cout<<dir<<endl;
	}
	return 0;
}