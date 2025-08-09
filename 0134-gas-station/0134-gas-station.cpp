class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totg = 0, totc=0;
        
        
        int start = 0,currg=0;
        for(int i =0;i<gas.size();i++) {
            totg+=gas[i];
            totc+=cost[i];
            currg+=(gas[i]-cost[i]);

            if(currg<0) {
                start = i+1;
                currg=0;
            }
        }
        if(totg<totc) {
            return -1;
        }
        return start;
    }
};