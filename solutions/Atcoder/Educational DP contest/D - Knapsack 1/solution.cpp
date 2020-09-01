#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int v[101], w[101];
long long dp[101][100005];

int main(){
    int n, W;
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    //dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1])
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= W; j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;   
}