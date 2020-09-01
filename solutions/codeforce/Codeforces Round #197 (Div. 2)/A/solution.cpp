#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    while(cin >> s){
        int n = s.size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(s[i] != '+')v.emplace_back(s[i]-'0');
        }
        sort(v.begin(), v.end());
        bool f = 0;
        for(auto & i : v){
            if(f)cout << '+';
            else f = 1;
            cout << i;
        }
        cout << endl;
    }
    return 0;
}