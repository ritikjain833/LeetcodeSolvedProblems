class Solution {
public:
    int m;
    int n;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(vector<vector<int>> &grid,int r,int c){
        if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1){
            grid[r][c]=0;
            for(int i=0;i<4;i++){
                dfs(grid,r+dr[i],c+dc[i]);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1 ){
                    dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};