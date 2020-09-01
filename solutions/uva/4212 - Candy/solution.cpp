    #include <bits/stdc++.h>
    using namespace std;

    int main(){

        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n, m;
        while(cin >> n >> m && n && m){
            vector<int> _dp(n);
            for(int i = 0; i < n; i++){
                vector<int> dp(m);
                for(int j = 0; j < m; j++){
                    cin >> dp[j];
                }
                int mmax = 0;
                for(int j = 0; j < m; j++){
                    if(j == 2)dp[j] = dp[0] + dp[j];
                    if(j > 2)dp[j] = max(dp[j-2],dp[j-3]) + dp[j];
                    mmax = max(mmax, dp[j]); 
                }
                _dp[i] = mmax;
            }
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(i == 2)_dp[i] = _dp[0] + _dp[i];
                if(i > 2)_dp[i] = max(_dp[i-2], _dp[i-3]) + _dp[i];
                ans = max(ans, _dp[i]);
            }
            cout << ans << endl;
        }
        return 0;
    }   