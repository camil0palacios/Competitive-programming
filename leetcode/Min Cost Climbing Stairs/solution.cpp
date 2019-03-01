vector<int> dp;
int go(vector<int> &v, int i){
    if(i >= v.size())return 0;
    if(dp[i] != -1)return dp[i];
    return dp[i] = min(go(v,i+1), go(v,i+2)) + v[i];
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int n = v.size();
        dp.assign(n, -1);
        return min(go(v,0), go(v,1));
    }
};