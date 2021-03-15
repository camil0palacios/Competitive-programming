#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// m = n * a + b + c;
// m / a = n

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int l, r, m;
        cin >> l >> r >> m;
        int a = 0, b = 0, c = 0;
        for(int i = l; i <= r; i++) {
            int a = i, b = l + (i % m), c = l;
            if(b <= r && m / i != 0) break;
            b = l, c = l + (i - (i % m));
            if(c <= r) break;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}