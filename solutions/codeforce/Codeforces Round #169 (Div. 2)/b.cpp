#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int v[26], odd = 0;
        memset(v, 0, sizeof v);
        for(int i = 0; i < s.size(); i++)v[s[i]-'a']++;
        for(int i = 0; i < 26; i++){
            if(v[i] && v[i] % 2)odd++;
        }
        if(odd % 2 || odd == 0)cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}