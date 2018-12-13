bool valid(vector<vector<int>> &v, int row, int col){
    if(row >= v.size() || col >= v[0].size())return false;
    if(v[row][col])return false;
    return true;
}

int recurse(vector<vector<int>> &v, vector<vector<int>> &dp, int row = 0, int col = 0){
    if(!valid(v,row,col))return 0;
    if(row == v.size() - 1 && col == v[0].size() - 1)return 1;
    if(dp[row][col] == -1)
        dp[row][col] = recurse(v, dp, row + 1, col) + recurse(v, dp, row, col + 1);
    return dp[row][col];
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return recurse(v,dp);
    }
};