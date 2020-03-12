#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int const inf = 1e9 + 7;
int n, W, v[101], w[101], dp[101][1100000];

// dp[i][j] = max(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1])

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 1100000; j++)
            dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 1100000; j++){
            dp[i][j] = dp[i-1][j];
            if(j - v[i-1] >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
            }
        }
    }
    int mmax = 0;
    for(int i = 0; i < 1100000; i++){
        if(dp[n][i] <= W)mmax = i;
    }
    cout << mmax << endl;
    return 0;
}