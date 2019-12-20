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
