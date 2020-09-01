#include <bits/stdc++.h>
using namespace std;

int n, m, a[15], dp[15][15];

int go(int idx, int last){
    if(idx == m)return 1;
    if(dp[idx][last] != -1)return dp[idx][last];
    int cnt = 0;
    for(int j = 0; j < n; j++){
        if(last == 0 || abs(a[j] - last) <= 2){
            cnt += go(idx+1,a[j]);
        }
    }
    return dp[idx][last] = cnt;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0,0) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}