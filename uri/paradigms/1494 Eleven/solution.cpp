#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
string s;
int a[10];

ll dp[11][51][901];

ll go(int idx, int k, int sum){
    if(idx == 10)return sum % 11 == 0 && k == 0; 
    if(dp[idx][k][sum] != -1)return dp[idx][k][sum];
    ll ans = 0;
    for(int i = 0; i <= a[idx]; i++){
        if(k - i >= 0){
            ans = (ans + go(idx + 1, k - i, sum + (a[idx] - i)*idx - i*idx)) % mod;
        }
    }
    return dp[idx][k][sum] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> s){
        for(int i = 0; i < s.size(); i++){
            a[s[i] - '0']++;
        }
        memset(dp, -1, sizeof dp);
        ll ans = go(0, s.size() / 2, 0); 
        cout << ans << endl;
    }
    return 0;
}