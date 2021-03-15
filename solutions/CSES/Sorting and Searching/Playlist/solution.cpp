#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, ans = 0;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        if(m.count(a[i])) {
            // cout << i << ' ' << a[i] << ' ' << m[a[i]] << endl;
            ans = max(ans, i - l);
            l = max(l, m[a[i]] + 1); 
        }
        // cout << i << ' ' << ans << endl;
        m[a[i]] = i;
    }
    ans = max(ans, n - l);
    cout << ans << endl;
    return 0;
}