class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        
        while (size>1) {
            sort(stones.begin(),stones.end());
            int last = stones[size-1];
            int lastsec = stones[size-2];
            if(last == lastsec) {
                size -=2;
            }
            else {
                stones[size-2] = last - lastsec;
                size--;
            }
        }
        if(size==0) return 0;
        else return stones[0];
    }
};