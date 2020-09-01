#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        long long f[101];
        if(a > b) swap(a, b);
        f[0] = a, f[1] = b;
        int ans = 0;
        for(int i = 2; i <= 100; i++) {
            ans++;
            f[i] = f[i - 1] + f[i - 2];
            if(f[i] > n) break;
        }
        cout << ans << endl;
    }
    return 0;
}