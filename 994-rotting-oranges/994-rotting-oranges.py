class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        queue=deque()
        count=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    queue.append((i,j,0))
                elif grid[i][j]==1:
                    count+=1
        directions=[[-1,0],[1,0],[0,1],[0,-1]]    
        if count==0:
            return 0
        while queue:
            r,c,dist=queue.popleft()
            for dr,dc in directions:
                nr=r+dr
                nc=dc+c
                if nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1:
                    grid[nr][nc]=2
                    queue.append((nr,nc,dist+1))
                    count-=1
                    if count==0:
                        return dist+1
        
        return -1
            
        