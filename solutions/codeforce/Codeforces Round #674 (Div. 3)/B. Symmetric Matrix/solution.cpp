#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool ok = 0;
        for(int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            ok |= (b == c);
        }
        cout << (ok && m % 2 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}

// 5 3 5 3
// 3 4 3 4
// 5 3 5 3
// 3 4 3 4 
