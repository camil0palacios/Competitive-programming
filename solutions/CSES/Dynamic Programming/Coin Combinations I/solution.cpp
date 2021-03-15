#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 101;
int coin[MXN];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int dp[x + 1];
    memset(dp, 0, sizeof dp);
    dp[x] = 1;
    for(int i = x - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(i + coin[j] <= x)
                add(dp[i], dp[i + coin[j]]); 
        }
    }
    cout << dp[0] << endl;
    return 0;
}