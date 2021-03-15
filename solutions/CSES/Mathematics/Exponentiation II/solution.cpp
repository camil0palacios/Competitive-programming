#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

void mul(ll & a, ll b, ll m) {
    a = a * b % m;
}

ll be(ll a, int b, ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) mul(ans, a, m);
        mul(a, a, m);
        b >>= 1;
    }
    return ans % m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << be(a, be(b, c, mod - 1), mod) << endl; 
    }
    return 0;
}