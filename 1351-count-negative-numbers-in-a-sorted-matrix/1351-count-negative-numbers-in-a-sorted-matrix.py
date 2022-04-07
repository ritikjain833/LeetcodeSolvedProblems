class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count=0
        m,n=len(grid),len(grid[0])
        i=m-1
        j=0
        while j<n and  i>=0:
            if grid[i][j]<0:
                count+=(n-j)
                i-=1
            else:
                j+=1
        return count        
        