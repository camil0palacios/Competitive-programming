#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n || m){
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int dp[n];
        for(int i = 0; i < n; i++){
            int tmp[m];
            memset(tmp, 0, sizeof tmp);
            for(int j = 0; j < m; j++){
                tmp[j] = max(j - 2 < 0 ? a[i][j] : tmp[j-2] + a[i][j], j - 1 < 0 ? a[i][j] : tmp[j-1]);
            }
            dp[i] = tmp[m-1];
        }
        int dp2[n];
        memset(dp2, 0, sizeof dp2);
        for(int i = 0; i < n; i++){
            dp2[i] = max(i - 2 < 0 ? dp[i] : dp2[i-2] + dp[i], i - 1 < 0 ? dp[i] : dp2[i-1]);   
        }
        cout << dp2[n-1] << endl;
    }
    return 0;   
}