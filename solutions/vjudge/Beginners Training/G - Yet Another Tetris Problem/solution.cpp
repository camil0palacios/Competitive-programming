#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], mn = 100;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        bool ok = 1;
        for(int i = 0; i < n; i++) {
            a[i] -= mn;
            ok &= a[i] % 2 == 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}