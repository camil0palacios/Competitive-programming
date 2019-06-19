#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int n, T, t[16], g[15];
int dp[256][(2 << 15) + 1][3];

int go(int d, int mask, int gen){
    if(d == T)return 1;
    if(dp[d][mask][gen] != -1)return dp[d][mask][gen];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(((mask >> i)&1) == 0 && g[i] != gen && t[i] + d <= T){
            ans += go(d + t[i], mask|(1 << i), g[i]);
            ans %= mod;
        }
    }
    return dp[d][mask][gen] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> T;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> g[i];
    }
    memset(dp, -1, sizeof dp);
    cout << go(0,0,0) << endl;
    return 0;
}