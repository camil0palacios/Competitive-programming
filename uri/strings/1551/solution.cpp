#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	int n;
	cin>>n;
	cin.ignore();
	while(n--){
		getline(cin,s);
		set<char> set;
		for(auto &i: s)
			if(isalpha(i) && set.find(i) == set.end())
				set.insert(i);

		if(set.size() == 26)cout<<"frase completa"<<endl;
		else if(set.size() >= 13)cout<<"frase quase completa"<<endl;
		else cout<<"frase mal elaborada"<<endl;
	}
	return 0;
}