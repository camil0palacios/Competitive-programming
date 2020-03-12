#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1000 * 2 + 10;

int n, c, t1, t2;
long long dp[MAXN], last;

long long go(int idx, vector<int> & a){
    if(idx >= last)return 0;
    if(dp[idx] != -1)return dp[idx];
    long long ans = 0;
    int nxt1 = upper_bound(a.begin(), a.end(), a[idx] + t1) - a.begin();
    int nxt2 = upper_bound(a.begin(), a.end(), a[idx] + t2) - a.begin();
    ans = min(go(nxt1, a) + t1, go(nxt2, a) + t2);
    return dp[idx] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> c >> t1 >> t2){
        vector<int> a(2*n);       
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i + n] = c + a[i];
        }
        long long ans = c;
        for(int i = 0; i < n; i++){
            last = i + n;
            memset(dp, -1, sizeof dp);
            ans = min(ans, go(i, a));
        }
        cout << ans << endl;
    }
    return 0;
}