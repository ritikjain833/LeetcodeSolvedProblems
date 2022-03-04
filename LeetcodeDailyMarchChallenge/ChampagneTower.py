class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        arr=[[0]*(query_row+1) for _ in range(query_row+1)]
        arr[0][0]=poured
        for i in range(query_row):
            for j in range(i+1):
                if arr[i][j]>1:
                    excess=arr[i][j]-1
                    arr[i+1][j]+=excess/2
                    arr[i+1][j+1]+=excess/2
                    arr[i][j]=1
        return min(1,arr[query_row][query_glass])           
                    
        
        
        
