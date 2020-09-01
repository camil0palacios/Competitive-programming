#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN], b[MXN], m[MXN], idx[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        idx[b[i]] = i;
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(idx[a[i]] < i) {
            mx = max(mx, ++m[n - (i + 1) + idx[a[i]] + 1]);
        } else {
            mx = max(mx, ++m[idx[a[i]] - i]);
        }
    }
    cout << mx << endl;
    return 0;
}