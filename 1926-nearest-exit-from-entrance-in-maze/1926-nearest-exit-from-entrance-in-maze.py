class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        queue=deque()
        m=len(maze)
        n=len(maze[0])
        visited=[[False]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if (i==0 or i==m-1) and maze[i][j]=="."  and (i!=entrance[0] or j!=entrance[1]):
                    visited[i][j]=True
                    queue.append((i,j,0))
                if (j==0 or j==n-1) and maze[i][j]=="." and (i!=entrance[0] or j!=entrance[1]):
                    visited[i][j]=True
                    queue.append((i,j,0))
        directions=[[-1,0],[1,0],[0,-1],[0,1]]
        #print(queue)
        
        while queue:
            r,c,dist=queue.popleft()
            visited[r][c]=True
            for dr,dc in directions:
                nr=r+dr
                nc=c+dc
                #print(nr,nc)
                if nr>=0 and nr<m and nc>=0 and nc<n and maze[r][c]=="." and visited[nr][nc]==False:
                    #print(1)
                    if nr==entrance[0] and nc==entrance[1]:
                        return dist+1
                    #print(queue)
                    visited[nr][nc]=True
                    queue.append((nr,nc,dist+1))
        return -1            
                    
    
    
            