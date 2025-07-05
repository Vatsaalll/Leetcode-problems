class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int ele : arr) {
            mp[ele]++;
        }
        int max = -1;
        for(auto& pair : mp) {
            if(pair.first == pair.second) {
                if(pair.first>max) {
                    max = pair.first;
                }
            }
        }
        return max;
    }
};