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
        int a[n], mn = 101;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        for(int i = 0; i < n; i++) {
            a[i] -= mn;
        }
        bool ok = 1;
        for(int i = 0; i < n; i++) {
            ok &= a[i] % 2 == 0;
        }
        cout << (ok ? "YES" : "NO") << endl; 
    }
    return 0;
}