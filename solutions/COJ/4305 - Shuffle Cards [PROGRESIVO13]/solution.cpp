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
        char cur = s[0];
        int ans = 0, n = (int)s.size();
        for(int i = 0; i < n; i++){
            if(cur != s[i]){
                ans++;
                cur = s[i];
            }
        }
        if(cur == 'a')ans++;
        cout << ans << endl;
    }
    return 0;
}