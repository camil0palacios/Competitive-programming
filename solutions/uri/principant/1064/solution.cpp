#include <bits/stdc++.h>
using namespace std;

int main(){
	
	double prom=0, pos=0,tmp;
	for(int i=0; i < 6; i++){
		cin>>tmp;
		if(tmp > 0){
			prom += tmp;
			pos++;
		}
	}
	cout<<pos<<" valores positivos\n";
	printf("%.1f\n", prom/pos);
	return 0;
}