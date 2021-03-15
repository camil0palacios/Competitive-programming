#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        fori(i, 0, n) cin >> a[i];
        fori(i, 0, n) cin >> b[i];
        auto can = [&](ll x) {
            ll acc = 0;
            fori(i, 0, n) {
                if(a[i] > x) acc += b[i]; 
            }
            return acc <= x;
        };
        ll l = 0, r = 1e18, ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(can(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}