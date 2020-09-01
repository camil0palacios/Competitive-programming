#include <bits/stdc++.h>
using namespace std;

int dp[(1 << 15)];
int n;

int go(vector<int> & h, vector<vector<int>> & d, int mask){
    if(mask == (1 << n)-1)return 0;
    if(dp[mask] != -1)return dp[mask];
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        if(((mask >> i)&1) == 0){
            int tmp = (mask |(1 << i)); 
            for(int j = 0; j < n; j++){
                if(((mask >> j)&1) && d[j][i] != 0){
                    ans = min(ans, ((h[i]+d[j][i]-1)/d[j][i]) + go(h,d,tmp));
                }
            }
            ans = min(ans, h[i] + go(h,d,tmp));     
        }
    }
    return dp[mask] = ans;
}

void solve(){
    cin >> n;
    vector<vector<int>> damage(n,vector<int> (n));
    vector<int> health(n);
    for(int i = 0; i < n; i++)cin >> health[i];
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            damage[i][j] = c-'0';
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(health, damage, 0);
}


int main(){
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cout << "Case " << x << ": ";
        solve();
        cout << endl;
    }
    return 0;
}