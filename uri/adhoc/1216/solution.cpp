#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s1,s2;
	int n,sum=0;
	double cont=0;
	while(cin>>s1>>s2){
		cin>>n;
		sum+=n;
		cont++;
	}
	double average=sum/cont;
	printf("%.1f", average);
	return 0;
}