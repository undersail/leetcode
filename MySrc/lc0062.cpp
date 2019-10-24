// https://leetcode-cn.com/problems/unique-paths/

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