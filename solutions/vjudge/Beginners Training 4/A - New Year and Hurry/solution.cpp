#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int m = 0, ans = 0;
    for(int i = 1; i <= n && m + 5 * i + k <= 240; i++) {
        ans++;
        m += 5 * i;
    }
    cout << ans << endl;
    return 0;
}

// 5*i m -> 1
// 160 m -> x