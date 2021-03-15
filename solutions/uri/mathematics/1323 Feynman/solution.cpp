#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll q[101];
    memset(q, 0, sizeof q);
    for(int i = 1; i <= 100; i++) {
        for(int len = 1; len <= i; len++) {
            ll sz = (i - len) + 1;
            q[i] += sz * sz;
        }
    }
    int n;
    while(cin >> n, n) {
        cout << q[n] << endl;
    }
    return 0;
}