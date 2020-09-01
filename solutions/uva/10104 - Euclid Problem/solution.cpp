#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b, int & x, int & y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (y1 * (a / b));
    return g;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    while(cin >> a >> b) {
        int x, y;
        int d = gcd(a, b, x, y);
        cout << x << ' ' << y << ' ' << d << endl;
    }
    return 0;
}