#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    long long n;
    cin >> s >> n;
    long long ans = 0;
    for(int i = 0; i < s.size() && i < n; i++){
        ans += s[i] == 'a';
    }
    if(s.size() < n){
        ans *= n / s.size();
        n = n % s.size();
        for(int i = 0; i < n; i++){
            ans += s[i] == 'a';
        } 
    }
    cout << ans << endl;
    return 0;
}