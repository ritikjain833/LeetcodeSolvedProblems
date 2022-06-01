class Solution:
    
    def bfs(self,land,directions,i,j,ans):
        queue=deque()
        queue.append((i,j))
        land[i][j]=0
    
        while queue:
            er,ec=queue.popleft()
            for dr,dc in directions:
                nr=dr+er
                nc=dc+ec
                if nr>=0 and nr<len(land) and nc>=0 and nc<len(land[0]) and land[nr][nc]==1:
                    land[nr][nc]=0
                    queue.append((nr,nc))
        ans.append([i,j,er,ec])            
                    
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        ans=[]
        m=len(land)
        n=len(land[0])
        stack=[]
        directions=[[-1,0],[0,1],[0,-1],[1,0]]
        for i in range(m):
            for j in range(n):
                if land[i][j]==1:
                    self.bfs(land,directions,i,j,ans)
        return ans            
                    
        