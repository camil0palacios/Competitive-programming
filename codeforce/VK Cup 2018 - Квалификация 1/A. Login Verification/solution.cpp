#include <bits/stdc++.h>
using namespace std;

void transform(string & s){
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))s[i] = tolower(s[i]);
        if(s[i] == 'l' || s[i] == 'i')s[i] = '1';
        if(s[i] == 'o')s[i] = '0';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    string s, t;
    while(cin >> s){
        transform(s); 
        cin >> n;
        bool flag = 1;
        for(int i = 0; i < n; i++){
            cin >> t;
            transform(t);
            if(t == s)flag = 0;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}