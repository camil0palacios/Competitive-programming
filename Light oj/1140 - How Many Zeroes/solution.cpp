#include <bits/stdc++.h>
using namespace std;

long long dp[33][33][2][2];

long long go(string & s, int idx, int cnt, bool top, bool first){
    if(idx == s.size())return cnt;
    if(dp[idx][cnt][top][first] != -1)return dp[idx][cnt][top][first];
    long long ans = 0;
    int mmax = (top ? s[idx]-'0' : 9);
    for(int i = 0; i <= mmax; i++){
        ans += go(s, idx+1, (first ? (cnt + (i == 0)) : 0), top && (i == mmax), ((i != 0) || first)); 
    }
    return dp[idx][cnt][top][first] = ans;
}

void solve(){
    string n, m;
    long long x, a;
    cin >> x >> n;
    if(x > 0){
        m = to_string(x-1);
        memset(dp, -1, sizeof dp);
        a = go(m,0,0,1,0);
    }else a = -1;
    memset(dp, -1, sizeof dp);
    cout << go(n,0,0,1,0) - a << endl;
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