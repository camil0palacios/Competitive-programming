#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 2e5 + 5;
struct day { int a, b, p; };
day d[MXN];
ll dp[MXN];

int bs(int l, int r, int val) {
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(d[mid].a > val) r = mid - 1, ans = mid;
        else l = mid + 1; 
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d[i].a >> d[i].b >> d[i].p;
    }
    sort(d, d + n, [&](const day & x, const day & y) { 
        return make_pair(x.a, x.b) < make_pair(y.a, y.b);
    });
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        int j = bs(i, n - 1, d[i].b);
        dp[i] = max(dp[i], d[i].p + (j != -1 ? dp[j] : 0));
    }
    cout << dp[0] << endl;
    return 0;
}