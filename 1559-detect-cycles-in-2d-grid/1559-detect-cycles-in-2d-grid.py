class Solution:
    def dfs(self,grid,char,r,c,parent_r,parent_c,directions,visited):
        visited[r][c]=True
        for dr,dc in directions:
            nr=r+dr
            nc=c+dc
            if(nr>=0 and nr<len(grid) and nc>=0 and nc<len(grid[0]) and grid[nr][nc]==char):
                #if already visited and parents are unequal
                if(visited[nr][nc]==True and nr!=parent_r and nc!=parent_c):
                    return True
                #it is not the parent and not have been visited yet
                if(visited[nr][nc]==False):
                    if(self.dfs(grid,char,nr,nc,r,c,directions,visited)):
                        return True
        
        
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m=len(grid)
        n=len(grid[0])
        directions=[[-1,0],[1,0],[0,1],[0,-1]]
        visited=[[False]*(n) for _ in range(m)]
        
        for r in range(m):
            for c in range(n):
                if (visited[r][c]==False and self.dfs(grid,grid[r][c],r,c,-1,-1,directions,visited)):
                    return True
        return False        
                
        