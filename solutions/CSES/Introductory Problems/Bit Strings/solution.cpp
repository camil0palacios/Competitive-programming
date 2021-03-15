#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

void mul(ll & a, ll b) {
    a = a * b % mod;
}

int be(ll a, int b) {
    ll ans = 1;
    while(b) {
        if(b & 1) mul(ans, a); 
        mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    cout << be(2, n) << endl;
    return 0;
}