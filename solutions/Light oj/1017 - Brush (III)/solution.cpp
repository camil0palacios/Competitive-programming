#include <bits/stdc++.h>
using namespace std;

int n, w, k, dp[105][105], x[105];

int go(int idx, int acc){
    if(acc >= k || idx >= n)return 0;
    if(dp[idx][acc] != -1)return dp[idx][acc];
    int cnt = 0, i;
    for(i = 0; i+idx < n; i++){
        if(x[idx] + w < x[idx+i])break;
        cnt++;
    }
    int ans = max(go(idx+i,acc+1) + cnt, go(idx+1,acc));
    return dp[idx][acc] = ans;
}

void solve(){
    cin >> n >> w >> k;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp >> x[i];
    }
    sort(x,x+n);
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