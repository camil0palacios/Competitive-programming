#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e6 + 5;
const int INF = 1e9;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[MXN];

int Dp(int acc) {
    if(acc == 0) return 0;
    if(dp[acc] != -1) return dp[acc];
    int ans = -INF;
    for(int i = 0; i < 10; i++) {
        if(acc - num[i] >= 0)
            ans = max(ans, Dp(acc - num[i]) + i);
    }   
    return dp[acc] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << Dp(n) << endl;
    return 0;
}