#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if(a > b) swap(a, b);
        if(b + x <= n) { b += x, x = 0; }
        else {x -= n - b; b = n; }
        a = max(1, a - x);
        cout << b - a << endl;
    }
    return 0;
}