// https://leetcode-cn.com/problems/unique-paths-ii/

// 动态规划：dp[i][j] 表示从(0,0)到达(i,j)的最多路径
// 注意：用例数值较大，出现整数溢出情况，使用int64_t解决，原因需进一步分析
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 处理特殊情况
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        if (m == 1 && n == 1) {
            return !obstacleGrid[0][0];
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<int64_t>> dp(m, vector<int64_t>(n, -1));
        // 初始化边界条件
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            // 第一列
            if (!obstacleGrid[i][0]) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = 0;
            }
        }
        for (int j = 1; j < n; j++) {
            // 第一行
            if (!obstacleGrid[0][j]) {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (dp[i][j] >= 0) {
                    continue;
                }
                // 任意一点只能从左边或上边来
                if (!obstacleGrid[i][j]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// 动态规划：dp[i][j] 表示从(i,j)到达(m,n)的最多路径
// 此实现只初始化了右下角一个点做为边界条件
class Solution {
private:
    uint8_t m;
    uint8_t n;
    int countPath(vector<vector<int>>& grid, vector<vector<int64_t>> & cnt, uint8_t i, uint8_t j) {
        if (cnt[i][j] >= 0) {
            return cnt[i][j];
        } else {
            cnt[i][j] = 0;
            if (j + 1 < n) {
                cnt[i][j] += (!grid[i][j + 1])*countPath(grid, cnt, i, j + 1);
            }
            if (i + 1 < m) {
                cnt[i][j] += (!grid[i + 1][j])*countPath(grid, cnt, i + 1, j);
            }
            return cnt[i][j];
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        if (m == 1 && n == 1) {
            return !obstacleGrid[0][0];
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<vector<int64_t>> pathCnt(m, vector<int64_t>(n));
        pathCnt[m-1][n-1] = !obstacleGrid[m-1][n-1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j < n - 1) {
                    pathCnt[i][j] = (!obstacleGrid[i][j]) * pathCnt[i][j + 1];
                } else if (j == n - 1 && i < m - 1) {
                    pathCnt[i][j] = (!obstacleGrid[i][j]) * pathCnt[i + 1][j];
                } else if (i < m - 1 && j < n - 1) {
                    pathCnt[i][j] = -1;
                }
            }
        }
        return countPath(obstacleGrid, pathCnt, 0, 0);
    }
};
