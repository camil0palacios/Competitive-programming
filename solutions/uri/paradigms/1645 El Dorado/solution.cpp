#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mxN = 110;
int n, k;
ll a[mxN];
ll dp[mxN][mxN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> k && (n || k)){
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++) dp[i][k] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int x = k - 1; x >= 0; x--) {
                for(int j = n - 1; j > i; j--) {
                    if(a[i] < a[j]) {
                        dp[i][x] += dp[j][x + 1];
                    }
                }
            } 
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += dp[i][1];
        }
        cout << ans << endl;
    }
    return 0;
}