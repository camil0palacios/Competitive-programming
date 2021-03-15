#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 13;
int n, k;
int dp[1 << MXN][99];

int cnt_inv(int msk, int num) {
    int inv = 0;
    for(int i = 1; i <= n; i++) {
        inv += ((msk >> (i - 1)) & 1) && i > num; 
    }
    return inv;
}

int go(int msk, int w) {
    if(msk == (1 << n) - 1) return w == 0;
    if(dp[msk][w] != -1) return dp[msk][w];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!((msk >> (i - 1)) & 1)) {
            int x = cnt_inv(msk, i);
            if(x <= w) ans += go(msk | (1 << (i - 1)), w - x);
        }
    }
    return dp[msk][w] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        // memset(dp, -1, sizeof dp);
        // cout << go(0, k) << endl;
        memset(dp, 0, sizeof dp);
        dp[(1 << n) - 1][0] = 1;
        for(int msk = (1 << n) - 2; msk >= 0; msk--) {
            for(int w = 0; w <= k; w++) {
                int ans = 0;
                for(int i = 1; i <= n; i++) {
                    if(!((msk >> (i - 1)) & 1)) {
                        int x = cnt_inv(msk, i);
                        if(x <= w) ans += dp[msk | (1 << (i - 1))][w - x];
                    }
                }
                dp[msk][w] = ans;
            } 
        }
        cout << dp[0][k] << endl;
    }
    return 0;
}