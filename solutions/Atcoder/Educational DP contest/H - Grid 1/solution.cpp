#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int dp[1001][1001];
char a[1001][1001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        if(a[0][i] != '#')dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i < m; i++){
        if(a[i][0] != '#')dp[i][0] = dp[i-1][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(a[i][j] !=  '#'){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}