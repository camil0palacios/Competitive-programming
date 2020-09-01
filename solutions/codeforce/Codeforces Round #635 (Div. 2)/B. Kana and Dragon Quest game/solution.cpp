#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x, n, m;
        cin >> x >> n >> m;
        for(int i = 0; i < n && x > 10; i++) {
            x /= 2; x += 10;
        }
        for(int i = 0; i < m; i++) {
            x -= 10;
        }
        cout << (x <= 0 ? "YES" : "NO") << endl;
    }
    return 0;
}