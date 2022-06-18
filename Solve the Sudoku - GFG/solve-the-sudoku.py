#User function Template for python3

class Solution:
    def valid(self,board,x,y,c):
        for i in range(9):
            if board[i][y]==c:
                return False
        for j in range(9):
            if board[x][j]==c:
                return False
        for i in range(3):
            for j in range(3):
                if board[(x//3)*3 + i][(y//3)*3 + j] == c:
                    return False 
        return True             
                    
                    
                
    
    #Function to find a solved Sudoku. 
    def SolveSudoku(self,grid):
        candidates=[1,2,3,4,5,6,7,8,9]        
        for i in range(9):
            for j in range(9):
                if grid[i][j]==0:
                    for c in candidates:
                        if self.valid(grid,i,j,c):
                            grid[i][j]=c
                            if self.SolveSudoku(grid):
                                return True
                            else:
                               
                                grid[i][j]=0
                    return False
        return True
        
        
    
    #Function to print grids of the Sudoku.    
    def printGrid(self,arr):
        if self.SolveSudoku(arr)==True:
            for i in arr:
                print(*i,end=" ")
            
        
        # Your code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    while(t>0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k+=1
                
        ob = Solution()
            
        if(ob.SolveSudoku(grid)==True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t-1
# } Driver Code Ends