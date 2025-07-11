class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result = {{}}; // Add the empty subset
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                
                vector<int> subset = result[i];
                subset.push_back(num);
                if (find(result.begin(), result.end(), subset) == result.end()) {
                result.push_back(subset);
                }
            }
        }

        return result;
    }
};