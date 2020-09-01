#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int A = (n - 2*a + b + c) / 3;
        int B = A + a - b;
        int C = A + a - c;
        if(A + B + C == n && A + a == B + b && A + a == C + c && B + b == C + c && A >= 0 && B >= 0 && C >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}