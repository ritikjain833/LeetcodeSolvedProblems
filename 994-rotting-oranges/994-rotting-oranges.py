class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        count=0
        queue=deque()
        m=len(grid)
        n=len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    count+=1
                elif grid[i][j]==2:
                    queue.append((i,j,0))
        directions=[[-1,0],[1,0],[0,-1],[0,1]]    
        #print(count)
        if count==0:
            return 0
        while queue:
            #print(queue)
            r,c,dist=queue.popleft()
            for dr,dc in directions:
                nr=dr+r
                nc=dc+c
                #print(nr,nc)
                if nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1:
                    count-=1
                    grid[nr][nc]=2
                    
                    queue.append((nr,nc,dist+1))
                    if count==0:
                        return dist+1
            #print(queue)    
                    
        return -1            
            
            
        