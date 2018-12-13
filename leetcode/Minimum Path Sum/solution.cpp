int recurse(vector<vector<int>> &v, int row, int col, vector<vector<int>> &dp){
    if(row == v.size() - 1 && col == v[0].size() - 1)return v[row][col];
    if(dp[row][col] != 0)return dp[row][col];
    int d=1000001, r=1000001;
    if(row + 1 < v.size())     d = recurse(v, row + 1, col, dp);
    if(col + 1 < v[0].size())  r = recurse(v, row, col + 1, dp);
    return dp[row][col] = min(d, r) + v[row][col];
    
}

class Solution {
public:
    // O(M x N)
    /*int minPathSum(vector<vector<int>>& v) {  // Botton up verison
        int m = v.size();
        int n = v[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof dp);
        dp[0][0] = v[0][0];
        for(int i = 1; i < m;i++)dp[i][0] = dp[i-1][0] + v[i][0];
        for(int i = 1; i < n;i++)dp[0][i] = dp[0][i-1] + v[0][i];
        for(int i = 1; i < m;i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + v[i][j];
            }
        }
        return dp[m-1][n-1];
    }*/
    
    int minPathSum(vector<vector<int>>& v) { // recursion 
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        return recurse(v, 0, 0, dp);
    }
};