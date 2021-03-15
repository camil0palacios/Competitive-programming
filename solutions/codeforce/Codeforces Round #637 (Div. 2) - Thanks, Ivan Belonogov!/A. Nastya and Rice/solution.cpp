#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ok = (a - b) * n > c + d || (a + b) *n < c - d;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}