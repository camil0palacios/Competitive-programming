#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long a, b, c, n;
        cin >> a >> b >> c >> n;
        long long A =  (n - 2*a + b + c) / 3;
        long long B = A + a - b;
        long long C = A + a - c;
        if(A + B + C == n && a + A == b + B && b + B == c + C && A >= 0 && B >= 0 && C >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}