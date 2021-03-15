#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = s.size();
        int ans = 0, cnt = 1000;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ans += min(a, b*cnt);
                cnt = 0;
            }
            else cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}