class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dp(cols, grid[0][0]);
        for (int i = 1; i < cols; ++i)
            dp[i] = grid[0][i] + dp[i - 1];
        for (int i = 1; i < rows; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < cols; ++j) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return dp[cols-1]; 
    }
};
