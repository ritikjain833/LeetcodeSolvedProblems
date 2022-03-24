class Solution:
    def dfs(self,grid,r,c,m,n,directions):
        if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1):
            grid[r][c]=0
            for dr,dc in directions:
                self.dfs(grid,dr+r,dc+c,m,n,directions)
                
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        directions=[[1,0],[-1,0],[0,1],[0,-1]]
        for r in range(m):
            for c in range(n):
                if r==0 or c==0 or r==m-1 or c==n-1:
                    self.dfs(grid,r,c,m,n,directions)
        ans=0
        for r in range(m):
            for c in range(n):
                if grid[r][c]==1:
                    ans+=1
        return ans            