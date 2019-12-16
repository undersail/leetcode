// https://leetcode-cn.com/problems/minimum-path-sum/

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
        for (int x = m - 2; x >= 0; x--) {
           dp[x][n - 1] = grid[x][n - 1] + dp[x + 1][n - 1]; 
        }
        for (int y = n - 2; y >= 0; y--) {
           dp[m - 1][y] = grid[m - 1][y] + dp[m - 1][y + 1]; 
        }
        for (int x = m - 2; x >= 0; x--) {
            for (int y = n - 2; y >= 0; y--) {
                if (dp[x][y] < 0) {
                    dp[x][y] = grid[x][y] + min(dp[x + 1][y], dp[x][y + 1]);
                }
            }
        }
        return dp[0][0];
    }
};