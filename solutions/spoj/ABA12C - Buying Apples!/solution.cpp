#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
int n, k, p[110];
int dp[110];

void clearDp() {
    for(int i = 0; i <= k; i++) 
        dp[i] = INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < k; i++) {
            cin >> p[i];
        }
        clearDp();
        dp[k] = 0;
        for(int i = k - 1; i >= 0; i--) {
            int ans = INF;
            for(int j = 0; j < k; j++) {
                if(p[j] != -1 && i + (j + 1) <= k)
                    ans = min(ans, dp[i + (j + 1)] + p[j]);
            }
            dp[i] = ans;
        }
        cout << (dp[0] < INF ? dp[0] : -1) << endl;
    } 
    return 0;
}