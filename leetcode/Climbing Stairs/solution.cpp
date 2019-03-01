vector<int> dp;
int go(int i, int & n){
    if(i >= n)return (i == n ? 1 : 0);
    if(dp[i] != -1)return dp[i];
    return dp[i] = go(i+1,n) + go(i+2,n);
}

class Solution {
public:
    int climbStairs(int n) {
        dp.assign(n, -1);
        return go(0,n);
    }
};