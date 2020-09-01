#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int mx = INT_MIN;
    for(int l = 0; l < m; l++) {
        vector<int> v(n);
        for(int r = l; r < m; r++) {
            for(int i = 0; i < n; i++) {
                v[i] += a[i][r];
            }
            int dp = 0;
            for(int i = 0; i < n; i++) {
                dp = max(v[i], dp + v[i]);
                mx = max(mx, dp);
            }
        }
    }
    cout << mx << endl;
    return 0;
}