class Solution:
    def rev(self,li,start,end):
        while start<end:
            li[start],li[end]=li[end],li[start]
            start+=1
            end-=1
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m=len(grid)
        n=len(grid[0])
        if (k)%(m*n)==0:
            return grid
        else:
            temp=[]
            for i in range(m):
                for j in range(n):
                    temp.append(grid[i][j])
            k=k%(m*n)
            self.rev(temp,0,m*n-1)
            self.rev(temp,0,k-1)
            self.rev(temp,k,m*n-1)
            for i in range(m):
                for j in range(n):
                    grid[i][j]=temp[i*n+j]
            return grid        
                   
            
        