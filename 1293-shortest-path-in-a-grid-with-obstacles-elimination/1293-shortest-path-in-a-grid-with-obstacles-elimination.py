class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m=len(grid)
        n=len(grid[0])
        #print(grid)
        if m == 1 and n == 1:
            return 0
        queue=deque()
        queue.append((0,0,k,0))
        directions=[[-1,0],[1,0],[0,1],[0,-1]]
        visited = set()
        visited.add((0,0,k))
        while queue:
            r,c,k,dist=queue.popleft()
            for dr,dc in directions:
                nr=r+dr
                nc=c+dc
                if nr>=0 and nr<m and nc>=0 and nc<n:
                    if grid[nr][nc]==1 and k>0 and (nr,nc,k-1) not in visited:
                        visited.add((nr,nc,k-1))
                        queue.append((nr,nc,k-1,dist+1))
                    if grid[nr][nc]==0  and  (nr,nc,k) not in visited:
                        if nr==m-1 and nc==n-1:
                            return dist+1
                        visited.add((nr,nc,k))
                        queue.append((nr,nc,k,dist+1))
        return -1                
                      
                