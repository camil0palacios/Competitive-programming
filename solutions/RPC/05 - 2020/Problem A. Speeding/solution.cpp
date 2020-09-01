#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 101;
int t[MXN], x[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> x[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans = max(ans, (x[i] - x[i - 1]) / (t[i] - t[i - 1]));
    }
    cout << ans << endl;
    return 0;
}