class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m=len(mat)
        n=len(mat[0])     
        if m==0:
            return mat
        dp=[[10**5]*(n) for _ in range(m)]
        queue=deque()
        for i in range(m):
            for j in range(n):
                if mat[i][j]==0:
                    dp[i][j]=0
                    queue.append([i,j])
        directions=[[-1,0],[1,0],[0,-1],[0,1]]
        while queue:
            r,c=queue.popleft()
            for dr,dc in directions:
                nr=r+dr
                nc=c+dc
                if nr>=0 and nr<m and nc>=0 and nc<n:
                    if dp[nr][nc]>1+dp[r][c]:
                        dp[nr][nc]=1+dp[r][c]
                        queue.append([nr,nc])
        return dp                
                
                    
        