#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll f = 1, p = 1;
    for(int i = 1; i < n; i++) {
        p = (p * 2) % mod;
        f = (f * i) % mod;
    }
    f = (f * n) % mod;
    cout << (f - p + mod) % mod << endl; 
    return 0;
}