#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        string s;
        int k;
        cin >> s;
        if(s == "donate")cin >> k, ans += k;
        else cout << ans << endl;
    }
    return 0;
}