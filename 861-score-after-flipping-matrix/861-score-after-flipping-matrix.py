class Solution:
    def print_matrix(self,grid,m,n):
        for i in range(m):
            for j in range(n):
                print(grid[i][j],end=" ")
            print()    
    def flip_row(self,grid,row,n):
        for i in range(n):
            grid[row][i]=grid[row][i]^1
    def flip_col(self,grid,col,m):
        for i in range(m):
            grid[i][col]=grid[i][col]^1
    def matrixScore(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        count_col=[0]*(n)
        for i in range(m):
            if grid[i][0]==0:
                self.flip_row(grid,i,n)
            for j in range(n):
                if grid[i][j]==1:
                    count_col[j]+=1
        final=0
        for j in range(n):
            if count_col[j]<=(m//2):
                self.flip_col(grid,j,m)
        #self.print_matrix(grid,m,n)        
        for i in range(m):
            count=0
            for j in range(n):
                count=count*2+grid[i][j]
            final+=count
        return final    
                