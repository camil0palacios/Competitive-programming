#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int> ii;

const int MXN = 1005;
ii a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        int x = 0, y = 0, ok = 1;
        string ans;
        for(int i = 0; i < n; i++) {
            if(y <= a[i].second) {
                ans += string(abs(x - a[i].first), 'R');
                ans += string(abs(y - a[i].second), 'U');
                x = a[i].first;
                y = a[i].second;
            } else {
                ok = 0;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}