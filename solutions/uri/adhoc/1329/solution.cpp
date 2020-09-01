#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int jhon=0,mary=0,n;
	while(true){
		cin>>n;
		if(n==0)break;
		else{
			int r;
			for(int i=0; i < n; i++){
				cin>>r;
				if(r)jhon++;
				else mary++;
			}
		}
		cout<<"Mary won "<< mary <<" times and John won "<< jhon<<" times"<<endl;
		jhon=0;mary=0;
	}
	return 0;
}