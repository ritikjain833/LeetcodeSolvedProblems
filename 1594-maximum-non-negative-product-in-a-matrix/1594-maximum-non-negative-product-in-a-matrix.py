class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        max_product=[[0]*(n) for _ in range(m)]
        min_product=[[0]*(n) for _ in range(m)]
        mod=10**9+7
        for i in range(m):
            for j in range(n):
                maxi=float("-inf")
                mini=float("inf")
                if i==0 and j==0:
                    maxi=grid[i][j]
                    mini=grid[i][j]
                if i>0:
                    temp_max=max(grid[i][j]*max_product[i-1][j],grid[i][j]*min_product[i-1][j])
                    maxi=max(temp_max,maxi)
                    temp_min=min(grid[i][j]*max_product[i-1][j],grid[i][j]*min_product[i-1][j])
                    mini=min(temp_min,mini)
                if j>0:
                    temp_max=max(grid[i][j]*max_product[i][j-1],grid[i][j]*min_product[i][j-1])
                    maxi=max(temp_max,maxi)
                    temp_min=min(grid[i][j]*max_product[i][j-1],grid[i][j]*min_product[i][j-1])
                    mini=min(temp_min,mini)
                max_product[i][j]=maxi
                min_product[i][j]=mini
        return max_product[-1][-1]%mod if max_product[-1][-1]>=0 else -1        
                    
        
        