#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        bool ok = (a - b) * n > c + d || (a + b) * n < c - d;
        cout << (ok ? "No" : "Yes") << endl;
    }
    return 0;
}