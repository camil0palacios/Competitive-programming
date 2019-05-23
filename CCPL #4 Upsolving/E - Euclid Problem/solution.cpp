#include <bits/stdc++.h>
using namespace std;
struct ecuation {
    long long x, y, b;
    ecuation(long long _x, long long _y, long long _b) {
        x = _x; y = _y; b = _b;
    }
    ecuation() {}
};

ecuation operator -(ecuation a, ecuation b) {
    return ecuation(a.x-b.x, a.y-b.y, a.b-b.b);
}
ecuation operator *(long long a, ecuation b) {
    return ecuation(a*b.x, a*b.y, a*b.b);
}

long long gcd_extended(long long a, long long b, long long &x, long long &y) {
    ecuation a1(1, 0, a), a2(0, 1, b);
    while(a2.b) {
        long long d = a1.b / a2.b;
        ecuation temp = a1 - (d * a2);
        a1 = a2;
        a2 = temp;
    }
    x = a1.x;
    y = a1.y;
    return a1.b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b;
    while(cin >> a >> b) {
        long long x, y;
        long long d = gcd_extended(a, b, x, y);
        cout << x << ' ' << y << ' ' << d << '\n';
    }
    return 0;
}