#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll INF = 1e18;
const int MXN = 202;
int n, k, x;
int a[MXN];
ll dp[MXN][MXN];

ll go(int i, int cnt) {
    if(n - k <= i - 1 && i - 1 < n && cnt == x) return 0; 
    if(dp[i][cnt] != -1) return dp[i][cnt];
    ll ans = -INF;
    for(int j = i; j < min(n, i + k); j++) {
        ans = max(ans, go(j + 1, cnt + 1) + a[j]);
    }
    return dp[i][cnt] = ans;
}

int main() {  
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    ll ans = go(0, 0);
    cout << (ans > 0 ? ans : -1) << endl;
    return 0;
}