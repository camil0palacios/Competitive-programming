#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, m;
    string s, ans;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> m >> s;
        if(s[0] == 'A'){
            if(m % 3 == 0 || m % 3 == 2)ans = s;
            else ans = "Bob";
        }else{
            if(m % 3 == 1 || m % 3 == 2)ans = s;
            else ans = "Alice";
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}