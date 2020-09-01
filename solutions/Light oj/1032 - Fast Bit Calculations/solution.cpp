#include <bits/stdc++.h>
using namespace std;

long long dp[32][2][2][100];

long long dptop(int n, int idx, bool top, bool last, int acc){
    if(idx < 0)return acc;
    if(dp[idx][top][last][acc] != -1)return dp[idx][top][last][acc];
    long long ans = 0;
    int mmax = (top ? ((n >> idx) & 1) : 1);
    for(int i = 0; i <= mmax; i++){
        ans += dptop(n,idx-1,top && (i == mmax),i,acc + (last == 1 && i == 1));
    }
    return dp[idx][top][last][acc] = ans;
}

void solve(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof dp);
    cout << dptop(n,31,1,0,0) << endl;
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