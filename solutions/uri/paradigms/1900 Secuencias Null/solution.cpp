#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll ans = 0, ps = 0;
    map<ll, int> s;
    s[0]++;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ps += x; 
        if(s.count(ps)) ans += s[ps];
        s[ps]++;
    }
    cout << ans << endl;
    return 0;
}