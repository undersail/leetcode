// https://leetcode-cn.com/problems/unique-paths/

// 方法一：排列组合，左上到右下共需向右m-1步，向下n-1步，计算C((m+2-2),(m-1))即可
// C(n,m) = C(n,(n-m)) = P(n,m)/m! = n!/((n-m)!*m!)
// P(n,m) = n!/(n-m)!
// 注意：阶乘需要考虑结果较大的情况，可以使用double类型
class Solution {
private:
    int combination(int n, int m) {
        if (n < m) {
            return 0;
        }
        double comb = 1;
        for(int i = n; i > m; i--) {
            comb *= i;
        }
        for(int i = n - m; i > 0; i--) {
            comb /= i;
        }
        if (comb != (int)comb) {
            comb += 1;
        }
        return comb;
    }  
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        return combination(m + n - 2, m - 1);
    }
};

// 方法二：动态规划
// dp[i][j] 表示从(0,0)到达(i,j)的最多路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // 初始化边界条件
        for (int i = 0; i < m; i++) {
            // 第一列
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            // 第一行
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (dp[i][j] >= 0) {
                    continue;
                }
                // 任意一点只能从左边或上边来
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
