#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin,s)){
		string s1;
		for(auto &i: s){
			if( i >= 'a' && i <= 'z'){
				if(i + 13 > 'z') s1 +=  'a' + ( (i+13) - 'z') -1;
				else s1 += (i + 13);
			}
			else if(i >= 'A' && i <= 'Z'){
				if(i + 13 > 'Z') s1 +=  'A' + ( (i+13) - 'Z') - 1;
				else s1 += (i + 13);
			}
			else s1 += i;
		}
		cout << s1 << endl;
	}
	return 0;
}