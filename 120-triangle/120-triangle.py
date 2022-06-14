class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        for i in range(1,len(triangle)):
            for j in range(len(triangle[i])):
                #print(i,j)
                
                if j==0 and i>0:
                    triangle[i][j]=triangle[i-1][j]+triangle[i][j]
                elif j==(len(triangle[i])-1):
                    triangle[i][j]=triangle[i-1][j-1]+triangle[i][j]
                else:
                    triangle[i][j]=min(triangle[i-1][j-1],triangle[i-1][j])+triangle[i][j]
                    
        return (min(triangle[-1]))            
        