class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n + 2);
        tmp[0] = tmp[n + 1] = 1;
        for (int i = 1; i <= n; i ++) tmp[i] = nums[i - 1];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int step = 1; step <= n; step ++) {
            for (int i = 1; i + step - 1 <= n; i ++) {
                int j = i + step - 1;
                for (int k = i; k <= j; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + tmp[i - 1] * tmp[k] * tmp[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};
