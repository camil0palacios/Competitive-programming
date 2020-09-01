#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[31][901], fact[31];

ll go(ll n, ll k){
    if(k == 1)return n;
    if(n == k)return 1;
    if(dp[n][k] != -1)return dp[n][k];
    else return dp[n][k] = go(n-1,k) +  go(n-1,k-1);
}

int main(){
    int t, n, k;
    memset(fact, 1, sizeof fact);
    fact[0] = 1;
    for(int i = 1; i < 31; i++){
        fact[i] = fact[i-1]*i;
    }
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> n >> k;
        memset(dp, -1, sizeof dp);
        ll ans;
        if(n < k)ans = 0;
        else if(k == 0)ans = 1;
        else ans = go(n,k)*go(n,k)*fact[k];
        cout << "Case " << x << ": " << ans << endl;
    }
    return 0;
}