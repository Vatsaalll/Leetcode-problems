class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        vector<int>prev = points[0];
        int count = 1;
        for(int i =0;i<n;i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            int prevStart = prev[0];
            int prevEnd = prev[1];

            if(currStart > prevEnd) { //no overlap
                count++;
                prev = points[i];
            }
            else { // overlap ho rha
                prev[0] = max(prevStart, currStart);
                prev[1] = min(currEnd, prevEnd);
            }
        }
        return count;
    }
};