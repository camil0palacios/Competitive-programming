#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 110;
const int MXK = 100005;
int n, k;
int v[MXN], w[MXN];
// ll dp[MXN][MXK];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(k + 1, 0);
    for(int i = 1; i <= n; i++) {
        vector<ll> dpt(k + 1, 0);
        for(int j = 0; j <= k; j++) {
            dpt[j] = dp[j];
            if(j - w[i] >= 0) {
                dpt[j] = max(dpt[j], dp[j - w[i]] + v[i]);
            }
        }
        dp = dpt;
    }
    cout << dp[k] << endl;
    return 0;
}