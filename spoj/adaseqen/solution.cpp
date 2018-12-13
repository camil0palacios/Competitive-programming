#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<long long> alph(26);
        for(auto &i : alph)cin >> i;
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, 0));
        string s1, s2;
        cin >> s1 >> s2;
        for(int i = 1; i < n + 1; i++){ 
            for(int j = 1; j < m + 1; j++){
                if(s2[j - 1] == s1[i - 1]){
                   dp[i][j] = dp[i-1][j-1] + alph[s1[i - 1] - 'a']; 
                }  
                else dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}