#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[100005][3], a[100005][3], n;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    //dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i-1][k]) where k != j
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = 0;
            for(int k = 0; k < 3; k++){
                if(j != k){
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i-1][k]);
                }
            }
        }
    }
    int mmax = 0;
    for(int i = 0; i < 3; i++)mmax = max(mmax, dp[n][i]);
    cout << mmax << endl;
    return 0;
}