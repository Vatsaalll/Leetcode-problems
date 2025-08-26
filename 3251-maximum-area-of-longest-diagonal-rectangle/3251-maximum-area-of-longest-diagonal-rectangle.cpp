class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxd = 0;
        int maxa = 0;
        
        for(int i=0;i<dimensions.size();i++) {
            int length = dimensions[i][0];
            int breadth = dimensions[i][1]; 
            int diagonal = length*length + breadth*breadth;
            int area = length*breadth;
            if(diagonal > maxd) {
                maxd = diagonal;
                maxa = area;
            }
            else if(diagonal == maxd){
                if(area > maxa) {
                    maxa = area;
                }
            }
        }
        return maxa;
    }
};