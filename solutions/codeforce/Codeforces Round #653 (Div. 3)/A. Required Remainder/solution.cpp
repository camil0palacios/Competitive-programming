#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x, y, n;
        cin >> x >> y >> n;
        int m = (n - y) / x;
        cout << x * m + y << endl;
    }
    return 0;
}