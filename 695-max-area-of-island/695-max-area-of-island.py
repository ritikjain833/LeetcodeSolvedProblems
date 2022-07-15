class Solution:
    def dfs(self,grid,r,c,m,n):
        if r<0 or r>=m or c<0 or c>=n or grid[r][c]==0 :
            return 0
        grid[r][c]=0
        return 1+self.dfs(grid,r,c+1,m,n)+self.dfs(grid,r,c-1,m,n)+self.dfs(grid,r+1,c,m,n)+self.dfs(grid,r-1,c,m,n)
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        #visited=[[False]*(n) for _ in range(m)]
        area=0
        for i in range(m):
            for j in range(n):
                
                if grid[i][j]==1:
                    area=max(area,self.dfs(grid,i,j,m,n))
        return area            
                
                
                
        