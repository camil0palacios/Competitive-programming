#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<long long> v(n);
        for(auto & i : v)cin >> i;
        long long dp[10005][2] = {0};
        bool turn = 0;
        for(int len = 2; len <= n; len+=2){
            bool other = turn^1;
            for(int i = 0; i + len - 1 < n; ++i){
                dp[i][turn] = max(v[i] + min(dp[i+1][other], dp[i+2][other]),
                            v[i+len-1] + min(dp[i][other], dp[i+1][other]));
            }
            turn = other;
        }
        turn ^= 1;
        cout << dp[0][turn] << endl;
    }
    return 0;
}