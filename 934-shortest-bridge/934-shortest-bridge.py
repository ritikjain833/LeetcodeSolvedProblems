class Solution:
    # idea 1)find first land in the matrix
    # 2) use dfs to store all the land connected to one of the island
    # 3) use bfs to find the shorest distance between to islands.
    # avoid dijkstra because edges doesn't have weights
    def invalid(self,r,c,n):
        if r<0 or c<0 or r==n or c==n:
            return True
    def dfs(self,grid,visit,directions,n,r,c):
        if (self.invalid(r,c,n) or grid[r][c]==0 or (r,c) in visit):
            return 
        visit.add((r,c))
        for dr,dc in directions:
            self.dfs(grid,visit,directions,n,dr+r,dc+c)
            
    def bfs(self,grid,directions,visit,n):
        res=0
        q=deque(visit)
        while q:
            lenth=len(q)
            for _ in range(lenth):
                r,c=q.popleft()
                for dr,dc in directions:
                    curR=dr+r
                    curC=dc+c
                    if self.invalid(curR,curC,n) or (curR,curC) in visit:
                        continue
                    if grid[curR][curC]==1:
                        return res
                    q.append((curR,curC))
                    visit.add((curR,curC))
            res+=1        
        
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n=len(grid)
        visit=set()
        directions=[[0,1,],[0,-1],[1,0],[-1,0]]
        for r in range(n):
            for c in range(n):
                if grid[r][c]==1:
                    self.dfs(grid,visit,directions,n,r,c)
                    ans=self.bfs(grid,directions,visit,n)
                    return ans
        