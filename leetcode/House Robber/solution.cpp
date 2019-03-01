vector<int> dp;

int go(vector<int> & v, int i){
    if(i >= v.size())return 0;
    if(dp[i] != -1)return dp[i];
    return dp[i] = max(go(v, i + 1), go(v, i + 2) + v[i]);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return go(nums, 0);
    }
};