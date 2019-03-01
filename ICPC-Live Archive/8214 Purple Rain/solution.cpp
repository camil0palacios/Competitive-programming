#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        int n = s.size();
        vector<int> dp(n+1, 0);
        int j = 0, mmax = 0;
        for(int i = 1; i <= n; i++){
            int x = (s[i-1] == 'B' ? 1 : -1);
            dp[i] = max(x, dp[i-1] + x);
            if(dp[i] > mmax){
                mmax = dp[i];
                j = i;
            }
        }
        dp.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            int x = (s[i-1] == 'R' ? 1 : -1);
            dp[i] = max(x, dp[i-1] + x);
            if(dp[i] == mmax){
                j = min(j, i);
            }
            else if(dp[i] > mmax){
                mmax = dp[i];
                j = i;
            }
        }
        cout << j - mmax  - 1 << " " << j << endl;
    }
    return 0;
}