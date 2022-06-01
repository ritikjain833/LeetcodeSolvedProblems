class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m=len(mat)
        n=len(mat[0])     
        if m==0:
            return 0
        dp=[[10**5]*(n) for i in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j]==0:
                    dp[i][j]=0
                else:
                    if i>0:
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+1)
                    if j>0:
                        dp[i][j]=min(dp[i][j],dp[i][j-1]+1)
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i<m-1:
                    dp[i][j]=min(dp[i][j],dp[i+1][j]+1)
                if j<n-1:
                    dp[i][j]=min(dp[i][j],dp[i][j+1]+1)
        return dp            
                        
                    
        