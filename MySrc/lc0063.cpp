// https://leetcode-cn.com/problems/unique-paths-ii/

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