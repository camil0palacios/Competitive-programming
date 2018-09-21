#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		int cont=0;
		for(auto &i: s){
			if(i =='1')cont += 2;
			if(i =='2')cont += 5;
			if(i =='3')cont += 5;
			if(i =='4')cont += 4;
			if(i =='5')cont += 5;
			if(i =='6')cont += 6;
			if(i =='7')cont += 3;
			if(i =='8')cont += 7;
			if(i =='9')cont += 6;
			if(i =='0')cont += 6;
		}
		cout<<cont<<" leds"<<endl;
	}
	return 0;
}