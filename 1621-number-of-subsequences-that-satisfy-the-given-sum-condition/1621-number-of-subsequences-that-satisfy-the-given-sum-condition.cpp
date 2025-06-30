class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1000000007;
        vector<int>pre={1};
        for(auto i =1; i<=nums.size();i++) {
            pre.push_back((pre.back()<<1)%mod);
        }
        sort(nums.begin(), nums.end());
        for(int i=0, j =nums.size()-1;i<=j;i++) {
            while(i<=j && nums[i]+nums[j]>target) {
                j--;
            }
            if(j>=i) {
                int pw = pre[j-i];
                res = (res+pw) % mod;
            }
        }
        return res;
    }
};