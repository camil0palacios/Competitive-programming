#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll m = 100000007;
ll dp[51][1001];
int a[51], c[51], n, k;

ll go(int idx, ll acc){
    if(acc == k)return 1;
    if(idx == n)return 0;
    if(dp[idx][acc] != -1)return dp[idx][acc];
    ll ans = 0;
    for(int i = 0; i <= c[idx] && (i*a[idx]) + acc <= k; i++){
        ans += go(idx+1, acc + (i*a[idx]));
        ans = ans % m;
    }
    return dp[idx][acc] = ans % m;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> c[i];
    memset(dp, -1, sizeof dp);
    cout << go(0,0) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cout << "Case " << x << ": ";
        solve();
    }
    return 0;
}