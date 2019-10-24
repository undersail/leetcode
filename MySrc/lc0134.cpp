// https://leetcode-cn.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        int startNum = 0;
        int num = gas.size();
        int curIdx = 0;
        int i = 0;

        /*for (; i < num; i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        if(gasSum < costSum) 
            return -1;*/
        
        while(startNum < num){            
            if(gas[startNum] < cost[startNum]){
                startNum++;
            }
            else{
                gasSum = 0;
                costSum = 0;
                for(i = 0; i < num; i++){
                    curIdx = (startNum + i) % num;
                    gasSum += gas[curIdx];
                    costSum += cost[curIdx];
                
                    if(gasSum < costSum){
                        startNum++;
                        break;
                    }
                } 
                if(i < num) 
                    continue;
                else
                    break;
            }
        }
        
        if(startNum == num)
            return -1;
        else
            return startNum;
    }
};