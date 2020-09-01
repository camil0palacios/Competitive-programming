#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int mx = max( max(x, a - x - 1) * b, max(y, b - y - 1) * a);       
        cout << mx << endl;
    }
    return 0;
}