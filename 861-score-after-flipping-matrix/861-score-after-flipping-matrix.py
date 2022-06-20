#unoptimized approach
# class Solution:
#     # def print_matrix(self,grid,m,n):
#     #     for i in range(m):
#     #         for j in range(n):
#     #             print(grid[i][j],end=" ")
#     #         print()  
#     """ Logic used 
#     if the first bit of column[i][0] is zero flip all the particular row bits. that will maximize the value of that row.
#     then flip the column values if the count of the number of one is less than the half of the number of rows because they are at same bit position .so we maximizing the number of ones will overall increase the value.
#     finally calcutate the sum of value of each row.
#     Time Complexity=O(m*n)
    
#     """
#     def flip_row(self,grid,row,n):
#         for i in range(n):
#             grid[row][i]=grid[row][i]^1
#     def flip_col(self,grid,col,m):
#         for i in range(m):
#             grid[i][col]=grid[i][col]^1
#     def matrixScore(self, grid: List[List[int]]) -> int:
#         m=len(grid)
#         n=len(grid[0])
#         count_col=[0]*(n)
#         for i in range(m):
#             if grid[i][0]==0:
#                 self.flip_row(grid,i,n)
#             for j in range(n):
#                 if grid[i][j]==1:
#                     count_col[j]+=1
#         final=0
#         for j in range(n):
#             if count_col[j]<=(m//2):
#                 self.flip_col(grid,j,m)
#         #self.print_matrix(grid,m,n)        
#         for i in range(m):
#             count=0
#             for j in range(n):
#                 count=(count<<1)+grid[i][j]
#             final+=count
#         return final    
class Solution:
    def matrixScore(self,grid: List[List[int]]) -> int:
        result=0
        m=len(grid)
        n=len(grid[0])
        result+=(1<<(n-1))*m
        for j in range(1,n):
            same=0
            for i in range(m):
                if grid[i][0]==grid[i][j]:
                    same+=1
            result+=(1<<(n-1-j))*max(m-same,same)
        return result    
            
                