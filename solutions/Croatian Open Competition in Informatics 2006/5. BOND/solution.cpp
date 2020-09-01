#include <bits/stdc++.h>
using namespace std;

double dp[21][(1<<20)+5];
int a[21][21], n;

double go(int idx, int mask){
    if(idx == n)return 1.0;
    if(dp[idx][mask] != -1.0)return dp[idx][mask];
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(!((mask >> i) & 1)){
            ans = max(ans, go(idx + 1, mask|(1 << i))*(a[idx][i]/100.0));
        }
    } 
    return dp[idx][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << 20) + 5; j++){
            dp[i][j] = -1.0;
        }
    }
    cout << fixed << setprecision(10) << go(0,0)*100.0 << endl;
    return 0;
}