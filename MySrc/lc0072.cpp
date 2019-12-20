// https://leetcode-cn.com/problems/edit-distance/submissions/

// 动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 处理特殊情况
        if (word1.size() == 0 && word2.size() == 0) {
            return 0;
        } else if (word1.size() == 0) {
            return word2.size();
        } else if (word2.size() == 0) {
            return word1.size();
        }

        // dp[i][j]表示word1的前i个字符与word2的前j个字符转换时的最小操作数
        // size扩充一行一列, 表示word1或word2为空的情形
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        // 处理边界
        for (int i = 0; i < word1.size() + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < word2.size() + 1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < word1.size() + 1; i++) {
            for (int j = 1; j < word2.size() + 1; j++) {
                if (dp[i][j] >= 0) {
                    continue;
                }
                // word2(j-1) 加一个字符转换为 word1(i)
                int dist1 = dp[i][j - 1] + 1;
                // word1(i-1) 加一个字符转换为 word2(j)
                int dist2 = dp[i - 1][j] + 1;
                // word1(i) 变化一个（或0个）字符转换为 word2(j)
                int temp = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                int dist3 = dp[i - 1][j - 1] + temp;
                // 取3种转换方法中操作数最小的一个
                temp = min(dist1, dist2);
                dp[i][j] = min(temp, dist3);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
