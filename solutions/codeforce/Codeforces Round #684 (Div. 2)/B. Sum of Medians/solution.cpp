#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1000*1000 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n*k; i++) cin >> a[i];
        sort(a, a + n*k);
        int top = (n + 1) / 2;
        ll ans = 0;
        for(int i = k*(top - 1); i < n*k; i += n - top + 1) {
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}