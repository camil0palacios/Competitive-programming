#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	while(getline(cin,s)){
		bool n= false;
		for(auto &i : s){
			if(i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z')
				if(!n){
					i = toupper(i);
					n = true;
				}
				else {
					i = tolower(i);
					n = false;
				}
		}
		cout << s << endl;
	}
	return 0;
}