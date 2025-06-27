class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for(int n : nums) {
            count[n]++;
        }
        vector<pair<int, int>>arr;
        for(const auto& p : count) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int>res;
        for(int i = 0;i<k;i++) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};