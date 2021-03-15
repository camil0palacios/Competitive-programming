#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define ll long long
using namespace std;

typedef pair<int,int> ii;
const int MXN = 3e5 + 5;
const ll mod = 998244353;
ll f[MXN], fi[MXN];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    return (f[n] * fi[r] % mod * fi[n - r]) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    f[0] = fi[0] = 1;
    for(int i = 1; i < MXN; i++) {
        f[i] = (f[i - 1] * i) % mod;
        fi[i] = be(f[i], mod - 2);
    }
    int n, k;
    cin >> n >> k;
    vector<ii> events;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        events.emplace_back(l, -i);
        events.emplace_back(r, +i);
    }
    sort(all(events));
    ll ans = 0;
    int cnt = 0, l = -1;
    for(auto & i : events) {
        int lst = cnt;
        if(i.second < 0) cnt++;
        if(i.second > 0) {
            if(cnt >= k) ans = (ans + nCr(cnt - 1, k - 1)) % mod;
            cnt--;
        } 
    }
    cout << ans << endl;
    return 0;
}