class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int min1 = 1e9+7;
        for(const auto& t : tasks) {
            int start = t[0];
            int duration = t[1];
            int finish = start+duration;
            min1 = min(min1, finish);
        }
        return min1;
    }
};