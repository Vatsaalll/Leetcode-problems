class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();         
        int m = grid[0].size();       
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Push all initially rotten oranges into queue
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++)
                if(grid[i][j]==2){       
                    q.push({{i,j},0});   
                    vis[i][j]=2;        
                }

        int ans=0; 
        // direction: up, right, down, left
        int dr[4]={-1,0,1,0}; 
        int dc[4]={0,1,0,-1};  

        // Step 2: BFS traversal
        while(!q.empty()){
            auto [p,t]=q.front(); q.pop();
            ans=max(ans,t);    

            // Check 4 directions for fresh oranges
            for(int k=0;k<4;k++){
                int r=p.first+dr[k], c=p.second+dc[k];
                // Valid cell && fresh orange && not visited yet
                if(r>=0&&c>=0&&r<n&&c<m&&grid[r][c]==1&&!vis[r][c]){
                    vis[r][c]=2;        
                    q.push({{r,c},t+1}); 
                }
            }
        }

        // Step 3: Check if any fresh orange remains
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++)
                if(grid[i][j]==1 && vis[i][j]!=2) 
                    return -1;          

        return ans; 
    }
};