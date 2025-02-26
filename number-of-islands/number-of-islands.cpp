class Solution {
public:
    vector<int> directions={1,0,-1,0,1};
    void bfs(vector<vector<char>>& grid,int r,int c,int m,int n)
    {   queue<pair<int,int>> q;
        //visited[r][c]=true;
        q.push({r,c});
        grid[r][c]='0';
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            int row=node.first,col=node.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+directions[i];
                int nc=col+directions[i+1];
                if(nr>=0 and nr<m and nc>=0 and nc<n  and grid[nr][nc]=='1')
                {
                    q.push({nr,nc});
                    grid[nr][nc]='0';

                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
      // vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
        
    }
};
