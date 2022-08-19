class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>> &grid2,int i,int j){
        if(i<0 or i==m or j<0 or j==n or grid2[i][j]==0)
            return ;
        grid2[i][j]=0;
        dfs(grid2,i+1,j);
        dfs(grid2,i-1,j);
        dfs(grid2,i,j+1);
        dfs(grid2,i,j-1);
            
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        //removing all the non common subislands
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 and grid1[i][j]==0){
                    dfs(grid2,i,j);
                    
                }
            }
        }
        //finding all the common subislands
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    dfs(grid2,i,j);
                    count+=1;
                }
            }
        }
        return count;
    }
};