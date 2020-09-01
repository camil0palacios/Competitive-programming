#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    double ans = 1e9;
    for(int i = 0; i < n; i++) {
        double a, b; cin >> a >> b;
        ans = min(ans, (m * a) / b);
    }
    cout << ans << endl;
    return 0;
}