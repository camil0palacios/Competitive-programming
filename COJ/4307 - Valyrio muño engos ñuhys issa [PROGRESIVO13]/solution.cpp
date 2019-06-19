#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long dp[505][2];
long long c, v, n, k;
const long long mod = 1e9 + 7;

long long go(int idx, bool last){ // 0 cons 1 vowel
    //cout << idx << " " << last << endl;
    if(idx == n)return (last == 1);
    if(dp[idx][last] != -1)return dp[idx][last];
    long long ans = 0;
    if(last){
        for(int i = 0; i < v; i++){
            ans += go(idx + 1, 1);
            ans %= mod;
        }
        for(int i = 0; i < c; i++){
            ans += go(idx + 1, 0);
            ans %= mod;
        }
    }else{  
        for(int i = 0; i < v; i++){
            ans += go(idx + 1, 1) % mod;
            ans %= mod;
        }
    }
    return dp[idx][last] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> c >> v >> n >> k;
        memset(dp, -1, sizeof dp);
        long long ans = go(0,1);
        cout << ans;
        if(ans >= k)cout << " Accepted" << endl;
        else cout << " Rejected" << endl;
    }
    return 0;
}