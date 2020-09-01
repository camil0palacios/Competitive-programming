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
        int a[n], b[n];
        int ones = 0, mones = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ones += a[i] > 0;
            mones += a[i] < 0;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool ok = 1;
        for(int i = n - 1; i >= 0; i--) {
            ones -= a[i] > 0;
            mones -= a[i] < 0;
            if(a[i] == b[i]) continue;
            if(b[i] > 0 && !ones) ok = 0;
            else if(b[i] < 0 && !mones) ok = 0;
            else if(b[i] == 0 && a[i] > 0 && !mones) ok = 0;
            else if(b[i] == 0 && a[i] < 0 && !ones) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}