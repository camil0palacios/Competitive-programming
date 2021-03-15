#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string ans;
    int st = n < m ? 1 : 0;
    while(n != 0 && m != 0) {
        if(st) {
            if(m <= n) { m--, ans += "1"; }
            else { m -= 2, ans += "11"; }
        } else {
            ans += "0";
            n--;
        }
        st ^= 1;
    }
    if(ans.back() == '0' && m <= 2) {
        ans += string(m, '1');
        m = 0;
    }
    else if(ans.back() == '1' && n < 2) {
        ans += "0";
        n = 0;
    }
    if(n || m) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}