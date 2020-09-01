#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        long long ans = 0, cur = 0;
        for(int i = 0; i < s.size(); i++) {
            cur += s[i] == '+' ? 1 : - 1;
            if(cur < 0) {
                cur = 0;
                ans += (i + 1);
            }
        }
        ans += s.size();
        cout << ans << endl;
    }
    return 0;
}