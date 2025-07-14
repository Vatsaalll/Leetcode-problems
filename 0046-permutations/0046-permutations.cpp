class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        perms(nums,0,ans);
        return ans;
    }

private:
    void perms(vector<int>& nums, int index, vector<vector<int>>& result) {
        if(index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++) {
            swap(nums[index],nums[i]);
            perms(nums,index+1,result);
            swap(nums[index],nums[i]);
        }
    }
};