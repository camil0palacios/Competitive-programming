#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string punto;
	int d1,h1,m1,s1,d2,h2,m2,s2,df,hf,mf,sf;

	cin>>punto;cin>>d1;
	cin>>h1;cin>>punto;
	cin>>m1;cin>>punto;
	cin>>s1;
	cin>>punto;cin>>d2;
	cin>>h2;cin>>punto;
	cin>>m2;cin>>punto;
	cin>>s2;

	sf = 60-s1+s2;
	mf = (60-m1-1+m2)*60;
	hf = (23-h1+h2)*3600;
	df = (d2-d1-1)*86400;
	int total = sf+mf+hf+df;
 	int res;
	res = total % 86400;
	total = total / 86400;
	cout<<total<<" dia(s)\n";
	total = res;
	res = total % 3600;
	total =  total / 3600;
	cout<<total<<" hora(s)\n";
	total = res;
	res = total % 60;
	total =  total / 60;
	cout<<total<<" minuto(s)\n";
	cout<<res<<" segundo(s)\n";

	return 0;
}