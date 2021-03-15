#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void solve(ll n) {
    int a, b, c, d, pos_m = 0;
    for(ll p3 = 1; p3 * p3 <= n; p3++) {
        for(ll m = 1; p3 * m <= n; m++) {
            ll p4 = p3 * m * m;
            ll p2 = p3 * m + m;
            ll p1 = p3 * m - m;
            if(p1 + p2 + p3 + p4 == n && pos_m < m) {
                pos_m = m, a = p1, b = p2, c = p3, d = p4;
            }
        }
    }
    if(pos_m) cout << pos_m << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl; 
    else cout << n << " nao e quadripartido" << endl;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, cs = 0;
    while(cin >> n, n) {
        cout << "Instancia " << ++cs << endl;
        solve(n);
    }
    return 0;
}