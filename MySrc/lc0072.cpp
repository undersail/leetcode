// https://leetcode-cn.com/problems/edit-distance/submissions/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 && word2.size() == 0) {
            return 0;
        } else if (word1.size() == 0) {
            return word2.size();
        } else if (word2.size() == 0) {
            return word1.size();
        }

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
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
                int dist1 = dp[i][j - 1] + 1;
                int dist2 = dp[i - 1][j] + 1;
                int temp = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                int dist3 = dp[i - 1][j - 1] + temp;
                temp = min(dist1, dist2);
                dp[i][j] = min(temp, dist3);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};