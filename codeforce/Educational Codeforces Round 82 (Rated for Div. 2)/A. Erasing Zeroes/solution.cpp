#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int a = 0, b = s.size() - 1, ans = 0;
        for(int i = 0; i < s.size() && s[i] != '1'; i++){ a++; }
        for(int i = s.size() - 1; i >= 0 && s[i] != '1'; i--){ b--; }
        for(int i = a; i <= b; i++){
            ans += s[i] == '0';
        }
        cout << ans << endl;
    }
    return 0;
}