#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int mx = 0, s = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
            if(s % x != 0) {
                mx = i;
            }
        }
        s = 0;
        for(int i = n; i >= 1; i--) {
            s += a[i];
            if(s % x != 0) {
                mx = max(mx, n - i + 1);
            }
        }
        cout << (mx != 0 ? mx : -1) << endl;
    }
    return 0;
}