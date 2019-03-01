#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    while(cin >> s){
        int n = s.size();
        vector<bool> v(n,1);
        for(int i = 0; i < n - 2; i++){
            if(s.substr(i,3) == "WUB"){
                for(int j = 0; j < 3; j++){
                    v[i+j] = 0;
                }
            }
        }
        string ns;
        bool f = 0;
        for(int i = 0; i < n; i++){
            if(v[i]){
                ns += s[i];
                f = 1;
            }
            else if(!v[i] && f){
                ns += " ";
                f = 0;
            }
        }
        for(int i = 0; i < ns.size(); i++)
            cout << ns[i];
        cout << endl;
    }
    return 0;
}