#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int l, b;
        cin >> l >> b;
        int g = __gcd(l, b);
        l /= g, b /= g;
        cout << l * b << endl;
    }
    return 0;
}