#include <bits/stdc++.h>
using namespace std;

const int N =305;
const int M = 1005;
int dp[N][M];

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, n, k, c=1;
    cin >> q;
    while(q--){
        cin >> n >> k;
        int w[n],v[n];
        for(int i = 0; i < n; i++){
            cin >> v[i] >> w[i]; 
        }
        memset(dp, 0, sizeof dp);  
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i-1][j];
                if(w[i-1] - j <= 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
                }
            }
        }
        cout << "Galho " << c++ << ":" << endl;
        cout << "Numero total de enfeites: " << dp[n][k] << endl << endl;
    }
    return 0;
}