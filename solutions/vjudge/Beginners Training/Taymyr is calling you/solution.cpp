#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, z;
    cin >> n >> m >> z;
    int ans = 0;
    for(int i = n; i <= z; i += n) {
        if(i % m == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}