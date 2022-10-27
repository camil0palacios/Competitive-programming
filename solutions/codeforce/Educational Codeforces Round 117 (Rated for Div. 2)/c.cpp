#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

ll gauss(ll x) { return x * (x + 1) / 2; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        if (gauss(k) + gauss(k - 1) < x) {
            cout << 2 * k - 1 << endl;
            continue;
        }
        ll l = 1, r = 2 * k - 1, ans = 1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll cnt = gauss(min(mid, k));
            if (mid > k) {
                ll d = 2 * k - 1 - mid;
                cnt += gauss(k - 1) - gauss(d);
            }
            if (cnt >= x) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}