// https://leetcode-cn.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0) {
            return 0;
        }
        int nc = grid[0].size();
        int islandCnt = 0;
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (grid[r][c] == '1') {
                    islandCnt++;
                    // dfs(grid, r, c);
                    bfs(grid, r, c);
                }
            }
        }
        return islandCnt;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') {
            dfs(grid, r - 1, c);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
            dfs(grid, r, c - 1);
        }
        if (r + 1 < nr && grid[r + 1][c] == '1') {
            dfs(grid, r + 1, c);
        }
        if (c + 1 < nc && grid[r][c + 1] == '1') {
            dfs(grid, r, c + 1);
        }
    }
    
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        queue<pair<int, int>> neighbours;
        neighbours.push({r, c});
        while (!neighbours.empty()) {
            auto rc = neighbours.front();
            neighbours.pop();
            int row = rc.first;
            int col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
                neighbours.push({row-1, col});
                grid[row-1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
                neighbours.push({row, col-1});
                grid[row][col-1] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
                neighbours.push({row+1, col});
                grid[row+1][col] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
                neighbours.push({row, col+1});
                grid[row][col+1] = '0';
            }
        }
    }
};