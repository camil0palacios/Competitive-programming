#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

void sol() {
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ps[n + 1];
    ps[0] = 0;
    for(int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i - 1];
    }
    int ans = INT_MAX;
    for(int i = 1; i + p - 1 <= n; i++) {
        ans = min(ans, p*a[i + p - 2] - (ps[i + p - 1] - ps[i - 1]));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}