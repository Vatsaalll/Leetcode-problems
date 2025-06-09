#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto& p : freq) {
            int count = p.second;
            buckets[count].push_back(p.first);
        }
        
        vector<int> res;
        for (int i = n; i >= 1; --i) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};