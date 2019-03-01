#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 50005;
int dp[N];

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        memset(dp, 0, sizeof dp);
        dp[0] = dp[n+1] = 0;
        int mmax = 0;
        for(int i = 1; i <= n; i++){
            cin >> dp[i];
            if(dp[i] > dp[i-1])
                dp[i] = dp[i-1] + 1;
        }
        for(int i = n; i >= 1; i--){
            if(dp[i] > dp[i+1])
                dp[i] = dp[i+1] + 1;
        }
        for(int i = 0; i <= n; i++){
            mmax = max(mmax, dp[i]);
        }
        cout << mmax << endl;
    }
    return 0;
}