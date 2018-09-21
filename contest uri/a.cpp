#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	
	string s;
	while(getline(cin,s)){
		if(s == "esquerda")cout<<"ingles"<<endl;
		if(s == "direita")cout<<"frances"<<endl;
		if(s == "nenhuma")cout<<"portugues"<<endl;
		if(s == "as duas")cout<<"caiu"<<endl;
	}

	return 0;
}