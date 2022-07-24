class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        m=len(matrix)
        n=len(matrix[0])
        row=0
        col=n-1
        while row<m and col>=0:
            if matrix[row][col]==target:
                return True
            elif matrix[row][col]>target:
                col-=1
            elif matrix[row][col]<target:
                row+=1
        return False
              
        