#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[201][22][15];
int a[201], n, d, m, q;

ll go(int idx, int mod, int take){
    if(take == m)return (!mod ? 1 : 0);
    if(idx >= n)return 0;
    if(dp[idx][mod][take] != -1)return dp[idx][mod][take];
    return dp[idx][mod][take] = go(idx+1,mod,take) + go(idx+1,((mod + a[idx])%d + d)%d,take+1);
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> a[i];
    while(q--){
        cin >> d >> m;
        memset(dp, -1, sizeof dp);
        cout << go(0,0,0) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cout << "Case " << x << ":" << endl;
        solve();
    }
    return 0;
}