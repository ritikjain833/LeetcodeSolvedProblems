class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        large=float("inf")
        dp=[[large]*(n) for _ in range(m)]
        for i in range(n):
            dp[0][i]=grid[0][i]
        for i in range(1,m):
            for j in range(n):
                for k in range(n):
                    temp=dp[i-1][k]
                    cost=moveCost[grid[i-1][k]][j]+grid[i][j]+temp
                    dp[i][j]=min(dp[i][j],cost)
        return min(dp[-1])            
                    
            
        