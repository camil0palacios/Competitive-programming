#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN], w[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i, 0, n) cin >> a[i];
        fori(i, 0, k) cin >> w[i];
        sort(a, a + n);
        sort(w, w + k);
        int r = n - 1, l = 0;
        ll ans = 0;
        int i = 0;
        for(; i < k && w[i] == 1; i++) ans += 2*a[r--];
        for(; i < k; k--) { 
            ans += a[l] + a[r--];
            l += w[k - 1] - 1;
        }
        cout << ans << endl;
    }
    return 0;
}