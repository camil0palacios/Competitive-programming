#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int par=0,impar=0,neg=0,pos=0,tmp;
	for(int i=0; i < 5 ; i++){
		cin>>tmp;
		if(tmp%2 == 0)par++;
		else impar++;
		if(tmp > 0 )pos++;
		else if(tmp < 0)neg++;
	}
	cout<<par<<" valor(es) par(es)\n";
	cout<<impar<<" valor(es) impar(es)\n";
	cout<<pos<<" valor(es) positivo(s)\n";
	cout<<neg<<" valor(es) negativo(s)\n";
	return 0;
}