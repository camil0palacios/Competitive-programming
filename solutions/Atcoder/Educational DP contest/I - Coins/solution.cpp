#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

double p[3000];
double dp[3000][3000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    //dp[idx][heads] = dp[idx-1][heads]*p[idx-1] + dp[idx-1][heads-1]*(1 - p[idx-1])
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = (j ? dp[i-1][j-1]*p[i-1] : 0) + dp[i-1][j]*(1 - p[i-1]);
        }
    }
    double ans = 0;
    for(int i = 0; i <= n; i++){
        if(i > n - i)
            ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}