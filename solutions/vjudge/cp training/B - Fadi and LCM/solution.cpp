#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long x;
    cin >> x;
    pair<ll, ll> ans;
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0 && lcm(i, x / i) == x) {
            ans = make_pair(i, x / i);
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}