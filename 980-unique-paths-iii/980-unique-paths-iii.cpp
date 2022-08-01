class Solution {
public:
    int res=0;
    int sx,sy;
    int m,n;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    //starting one should also be counted as empty.
    //consider the example [[1,2]] here ans is one. and there is no empty boxes.
    int empty=1;
    void dfs(vector<vector<int>> &grid,int x,int y){
        if(x<0|| x>=m || y<0 || y>=n || grid[x][y]<0){
            return ;
        }
        if(grid[x][y]==2){
            if(empty==0){
                res++;
                
            }
            return ;
        }
        grid[x][y]=-2;
        empty--;
        // dfs(grid,x+1,y);
        // dfs(grid,x-1,y);
        // dfs(grid,x,y-1);
        
        // dfs(grid,x,y+1);
        for(int i=0;i<4;i++){
            dfs(grid,x+dr[i],y+dc[i]);
        }
        empty++;
        grid[x][y]=0;
        return ;

        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        dfs(grid,sx,sy);
        return  res;
        
    }
};