#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int ans = 0, cur = 0;
    for(int i = 0; i < s.size(); i++) {
        int p = s[i] - 'a';
        int mn = min(26 - p + cur, 26 - cur + p);
        if(abs(cur - p) < mn) {
            ans += abs(cur - p);
        } else {
            ans += mn;
        }
        cur = p;
    }
    cout << ans << endl;
    return 0;
}