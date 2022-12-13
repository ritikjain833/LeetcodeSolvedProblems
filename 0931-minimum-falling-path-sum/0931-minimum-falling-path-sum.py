class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m=len(matrix)
        n=len(matrix[0])
        for i in range(m):
            for j in range(n):
                if i==0 and j>0:
                    matrix[i][j]=matrix[i][j]
                elif j==0 and i>0:
                    if j+1<n:
                        matrix[i][j]=min(matrix[i-1][j+1],matrix[i-1][j])+matrix[i][j]
                    else:
                        matrix[i][j]=matrix[i-1][j]+matrix[i][j]
                elif i>0 and j>0:
                    if j+1<n:
                        matrix[i][j]=min(matrix[i-1][j],matrix[i-1][j-1],matrix[i-1][j+1])+matrix[i][j]
                    else:
                        matrix[i][j]=min(matrix[i-1][j],matrix[i-1][j-1])+matrix[i][j]
        return min(matrix[-1])            