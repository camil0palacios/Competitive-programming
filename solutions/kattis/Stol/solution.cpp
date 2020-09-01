#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];
char g[1001][1001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.'){
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.'){
                if(i-1 >= 0 && g[i-1][j] == '.'){
                    dp[i][j][0] += dp[i-1][j][0];
                }
                if(j-1 >= 0 && g[i][j-1] == '.'){
                    dp[i][j][1] += dp[i][j-1][1];
                }
            }
        }
    }
    int mmax = 0;
    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < m){
            if(g[i][j] == '.'){
                int cnt = 0, y;    
                for(y = j; y < m && dp[i][j][0] == dp[i][y][0]; y++){
                    cnt++;
                }
                mmax = max(mmax, cnt*2 + dp[i][j][0]*2 - 1);
                j = y;            
            }else j++;   
        }
    }
    for(int j = 0; j < m; j++){
        int i = 0;
        while(i < n){
            int cnt = 0, x;
            if(g[i][j] == '.'){
                for(x = i; x < n && dp[i][j][1] == dp[x][j][1]; x++){
                    cnt++;
                }
                mmax = max(mmax, cnt*2 + dp[i][j][1]*2 - 1);
                i = x;
            }else i++;
        }       
    }
    cout << mmax << endl;
    return 0;
}