#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	
	int n;
	string s,s1;
	cin>>s>>n;
	cin.ignore();
	while(n--){
		getline(cin,s1);
		string ans;
		int i = 0, j = 0;
		while(i < s1.size()){
			if(s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'u'){
				while(s1[i] != ' ' && i < s1.size()){
					int ss = (s[j] - 'a' + s1[i] - 'a');
					ans += ( ss < 26) ? (char)(ss + 'a'):(char)((ss + 'a') - 26);
					i++;j++;
					if(j > s.size()-1)j = 0;
				}
			}
			else{
				while(s1[i] != ' ' && i < s1.size()){
					ans += s1[i];
					i++;
				}
			}
			if(i < s1.size()){
				ans += s1[i];
				i++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}