#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        b /= 2;
        cout << max(min(b, p) * h + min(max(b - p, 0) , f) * c, min(b, f) * c + min(max(b - f, 0), p) * h) << endl;
    }
    return 0;
}