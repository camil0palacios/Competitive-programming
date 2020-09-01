#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = n - 1; i > 0; i--) {
            int mn = min(m - a[0], a[i]);
            a[0] += mn;
        }
        cout << a[0] << endl;
    }
    return 0;
}