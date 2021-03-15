#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    set<ll> s;
    s.insert(0);
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        sum += x;
        if(s.count(sum)) {
            ans++;
            s.clear();
            s.insert(0);
            sum = x;
        }
        s.insert(sum);
    }
    cout << ans << endl;
    return 0;
}