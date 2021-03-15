#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int Mxn = 18;
int c[Mxn][Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        int k = 1 << n;
        vector<int> dp(k, INF);
        dp[k - 1] = 0;
        for(int msk = k - 1; msk >= 0; msk--) {
            int j = __builtin_popcount(msk);
            for(int i = 0; i < n; i++) {
                if(!((msk >> i) & 1)) {
                    dp[msk] = min(dp[msk], dp[msk | (1 << i)] + c[i][j]);
                    // dp[msk | (1 << i)] = min(dp[msk | (1 << i)], dp[msk] + c[i][j]);
                } 
            }
        }
        cout << dp[0] << endl;
        // cout << dp[k - 1] << endl;
    }
    return 0;   
}