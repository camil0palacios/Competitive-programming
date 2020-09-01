#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n;
vector<int> a[22];
ll dp[1 << 22];

ll Dp(int msk) {
    if(msk == (1 << (n + 1)) - 2)return 1;
    if(dp[msk] != -1) return dp[msk];
    ll ans = 0;
    for(int j = 1; j <= n; j++) {
        if(!((msk >> j) & 1)) {
            bool ok = 1;
            for(int k = 0; k < a[j].size(); k++) {
                if(!((msk >> a[j][k]) & 1))ok = 0;
            }
            if(ok)ans += Dp(msk | (1 << j));
        }
    }
    return dp[msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= i - 1; j++) {
            if((i & j) == j){
                a[i].emplace_back(j);
            }
        }
    }
    memset(dp, -1, sizeof dp);
    cin >> n;
    cout << Dp(0) << endl;
    return 0;
}