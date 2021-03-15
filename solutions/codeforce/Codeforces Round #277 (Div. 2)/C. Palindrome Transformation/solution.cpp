#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    string s;
    cin >> n >> p >> s;
    n--, p--;
    if(p > n/2) {
        reverse(s.begin(), s.end());
        p = n - p;
    }
    int l = -1, r = 0;
    int ans = 0;
    for(int i = 0; i <= n/2; i++) {
        if(s[i] != s[n-i]) {
            int t = abs(s[i] - s[n-i]);
            ans += min(t, 26 - t);
            if(l < 0) l = i;
            else r = i;
        }
    }
    ans += min(abs(l - p), abs(r - p));
    ans += max(0, r - l);
    cout << (l < 0 ? 0 : ans) << endl;
    return 0;
}