#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    while(cin >> n >> s){
        long long cont = 0, suff = 1;
        for(int i = n - 1; i >= 0 && s[n-1] == s[i]; i--){
            suff++,cont++;
        }
        cont++;
        for(int i = 0; i < n && s[i] == s[0]; i++){
            if(s[i] == s[n-1]){ // its equal to the end 
                suff = (suff % mod + cont % mod) % mod;
            } else {
                suff = (suff % mod + 1)% mod;
            }
        }   
        cout << suff << endl;
    }
    return 0;
}