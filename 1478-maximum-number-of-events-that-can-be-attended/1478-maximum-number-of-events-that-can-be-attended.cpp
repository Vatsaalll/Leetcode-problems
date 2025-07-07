class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>minh;
        int day = 0, index = 0, n = events.size(), result = 0;
        while(!minh.empty() || index<n) {
            if(minh.empty()) {
                day = events[index][0];
            }
            while(index<n&&events[index][0]<=day) {
                minh.push(events[index][1]);
                index++;
            }
            minh.pop();
            result++;
            day++;
            while(!minh.empty() && minh.top() < day) {
                minh.pop();
            }
        }
        return result;
    }
};