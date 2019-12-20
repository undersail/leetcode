// https://leetcode-cn.com/problems/minimum-path-sum/

// 动态规划：dp[i][j]记录从(i,j)到右下角的路径最小和
class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        // 最后一列，只能向下走
        for (int i = m - 2; i >= 0; i--) {
           dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1]; 
        }
        // 最后一行，只能向右走
        for (int j = n - 2; j >= 0; j--) {
           dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1]; 
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (dp[i][j] < 0) {
                    // 任意一点只能向右或向下走
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
