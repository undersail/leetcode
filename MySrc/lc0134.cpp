// https://leetcode-cn.com/problems/gas-station/

// 暴力解法，注意暴力解法用时较多，预先计算gas.size()可节省一半时间
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSize = gas.size();
        int gasSum = 0;
        int costSum = 0;
        int startNum = 0;

        while(startNum < gasSize) {
            // 找起点
            if(gas[startNum] < cost[startNum]) {
                startNum++;
            } else {
                gasSum = 0;
                costSum = 0;
                // 尝试走完一圈
                int index = 0;
                for (index = 0; index < gasSize; index++) {
                    // 当前加油站的序号
                    int curNum = (startNum + index) % gasSize;
                    gasSum += gas[curNum];
                    costSum += cost[curNum];
                    if(gasSum < costSum){
                        startNum++;
                        break;
                    }
                }
                // 注意把此处判断放进循环中会导致超时
                if (index == gasSize) {
                    break;
                }
            }
        }
        if (startNum < gasSize) {
            return startNum;
        }
        return -1;  
    }
};
