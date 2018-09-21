#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	int n;
	cin>>n;
	cin.ignore();
	while(n--){
		getline(cin,s);
		vector<int> vec(1000,0);
		for(auto &i: s)
			if(isalpha(i))
				vec[tolower(i)]++;

		int max =  *max_element(vec.begin(),vec.end());
		for(char i = 'a'; i <= 'z'; i++)
			if(vec[i] == max)
				cout<<i;
		cout<<endl;
	}
	return 0;
}