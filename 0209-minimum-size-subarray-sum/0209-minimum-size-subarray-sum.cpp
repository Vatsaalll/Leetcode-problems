class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minwin = INT_MAX;
        int cursum = 0;
        int low=0, high = 0;
        while(high < nums.size()) {
            cursum +=nums[high];
            high++;
            while(cursum >= target) {
                int curwinsize = high - low;
                minwin = min(minwin, curwinsize);
                cursum -= nums[low];
                low++;
            }
        }
        return minwin == INT_MAX ? 0 : minwin;
    }
};