class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.mat=matrix
        m=len(matrix)
        n=len(matrix[0])
        for i in range(m):
            for j in range(n):
                if i==0 and j==0:
                    self.mat[i][j]=matrix[i][j]
                elif i>0 and j==0:
                    self.mat[i][j]=matrix[i][j]+matrix[i-1][j]
                elif i==0 and j>0:
                    self.mat[i][j]=matrix[i][j]+matrix[i][j-1]
                else:
                    self.mat[i][j]=matrix[i][j]+self.mat[i-1][j]+self.mat[i][j-1]-self.mat[i-1][j-1]
                    
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        aux=self.mat[row2][col2]
        if row1>0:
            aux=aux-self.mat[row1-1][col2]
        if col1>0:
            aux=aux-self.mat[row2][col1-1]
        if row1>0 and col1>0:
            aux=aux+self.mat[row1-1][col1-1]
        return aux    
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)