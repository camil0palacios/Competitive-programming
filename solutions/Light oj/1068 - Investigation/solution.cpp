#include <bits/stdc++.h>
using namespace std;

int dp[12][2][101][101], k;
string a, b;

string to_str(int x){
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    return s;
}

int dptop(string & s, int idx, bool top, int res, int sum){
    if(idx == s.size())return (res == 0 && sum == 0);
    if(dp[idx][top][res][sum] != -1)return dp[idx][top][res][sum];
    int ans = 0;
    int mmax = (top ? s[idx]-'0' : 9);
    for(int i = 0; i <= mmax; i++){
        ans += dptop(s, idx+1, top && i == mmax, (((res*10) % k) + i) % k, (sum+i) % k);
    }
    return dp[idx][top][res][sum] = ans;
}

void solve(){
    int x;
    cin >> x >> b >> k;
    if(k > 99){
        cout << 0 << endl;
        return;
    }
    a = to_str(x-1); 
    memset(dp, -1, sizeof dp);
    x = dptop(a,0,1,0,0);
    memset(dp, -1, sizeof dp);
    cout << dptop(b,0,1,0,0) - x << endl;
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