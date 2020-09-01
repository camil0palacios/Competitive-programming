#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        int p = 1e9;
        while(n) {
            while(n < p) { p /= 10; }
            ans += p;
            n -= p - p / 10;
        }
        cout << ans << endl;
    }
    return 0;
}