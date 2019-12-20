// https://leetcode-cn.com/problems/shortest-bridge/

// 当前结果：解答错误，70 / 96 个通过测试用例
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int nr = A.size();
        if (nr == 0) {
            return 0;
        }
        int nc = A[0].size();
        
        queue<pair<int, int>> island1;
        queue<pair<int, int>> island2;
        int cnt = FindIslands(A, island1, island2);
        if (cnt < 2) {
            return 1;
        }
        return cnt;
    }
    
private:
    int FindIslands(vector<vector<int>>& A, queue<pair<int, int>>& island1, queue<pair<int, int>>& island2)
    {
        int nr = A.size();
        int nc = A[0].size();
        int islandCnt = 0;
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (islandCnt == 0 && A[r][r] == '1') {
                    island1.push({r, c});
                    dfs(island1, A, r, c);
                    islandCnt++;
                    continue;
                }
                if (islandCnt == 1 && A[r][r] == '1') {
                    island2.push({r, c});
                    dfs(island2, A, r, c);
                    islandCnt++;
                    break; // just find 2 island
                }
            }
        }
        return islandCnt;
    }
    
    void dfs(queue<pair<int, int>>& island, vector<vector<int>>& A, int r, int c)
    {
        int nr = A.size();
        int nc = A[0].size();
        A[r][c] = '0';
        if (r - 1 >= 0 && A[r - 1][c] == '1') {
            island.push({r - 1, c});
            dfs(island, A, r - 1, c);
        }
        if (c - 1 >= 0 && A[r][c - 1] == '1') {
            island.push({r, c - 1});
            dfs(island, A, r, c - 1);
        }
        if (r + 1 < nr && A[r + 1][c] == '1') {
            island.push({r + 1, c});
            dfs(island, A, r + 1, c);
        }
        if (c + 1 < nc && A[r][c + 1] == '1') {
            island.push({r, c + 1});
            dfs(island, A, r, c + 1);
        }
    }
};
