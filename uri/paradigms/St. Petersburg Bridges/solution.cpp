#include <bits/stdc++.h>
using namespace std;

const int M = 105;
const int N = (M*(M+1))/2; 
int dp[M][N];

int main(){

    int n, m, u, v;
    while(cin >> n >> m){
        vector<int> de(n);
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            u--, v--;
            de[u]++;
            de[v]++;
        }
        memset(dp, 0, sizeof dp);
        dp[n][m] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= m; j++){
                dp[i][j] = dp[i+1][j];
                if(j + de[i] <= m){
                    dp[i][j] |= dp[i+1][j + de[i]];
                }
            }
        }
        cout << (dp[0][0] ? 'S' : 'N') << endl;
    }

    return 0;
}