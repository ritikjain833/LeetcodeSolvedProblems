class Solution:
    def dfs(self,grid,visited,r,c):
        if r<0  or r>=len(grid) or c<0 or c>=len(grid[0]) or (r,c) in visited or grid[r][c]=="0":
            return 0
        visited.add((r,c))
        return 1+self.dfs(grid,visited,r,c+1)+self.dfs(grid,visited,r,c-1)+self.dfs(grid,visited,r+1,c)+self.dfs(grid,visited,r-1,c)
            
   

    def numIslands(self, grid: List[List[str]]) -> int:
        m=len(grid)
        n=len(grid[0])
        visited=set()
        count=0
        for r in range(m):
            for c in range(n):
                if (r,c) not in visited and grid[r][c]=="1":
                    aux=self.dfs(grid,visited,r,c)
                    if aux>0:
                        count+=1
        return count 
        