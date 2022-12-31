class Solution {
public:
    int sx;
    int sy;
    int empty=1;
    int m;
    int n;
    int res=0;
    int dx[5]={-1,0,1,0,-1};
    
    void dfs(vector<vector<int>> &grid,int x,int y){
        if(x<0 or x>=m  or y<0 or y>=n or grid[x][y]<0){
            return ;
        }
        if(grid[x][y]==2){
            if(empty==0){
                res++;
            }
            return;
        }
        grid[x][y]=-2;
        empty--;
        
        for(int i=0;i<4;i++){
            
            dfs(grid,x+dx[i],y+dx[i+1]);
        }
        empty++;
        grid[x][y]=0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        dfs(grid,sx,sy);
        return res;
    }
};