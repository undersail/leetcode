// https://leetcode-cn.com/problems/deep-dark-fraction/

class Solution {
 private:
 
    int get_greatest_common_divisor(int num, int den)
    {
        int temp;
        int a = num;
        int b = den;
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        while(b != 0)
        {
            temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> res;
        if(cont.size() == 1) {
            res.push_back(cont[0]);
            res.push_back(1);
            return res;
        }
        
        int num = cont[cont.size() - 1];
        int den = 1;
        for (int i = cont.size() - 2; i >= 0; i--) {
            int temp = num;
            num = num*cont[i] + den;
            den = temp;
        }

        int gcd = get_greatest_common_divisor(num, den);
        num /= gcd;
        den /= gcd;
        res.push_back(num);
        res.push_back(den);
        return res;
    }
};