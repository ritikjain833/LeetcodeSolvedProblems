class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res=[]
        n=numRows
        for i in range(1,n+1):
            res.append([0]*(i))
        for i in range(len(res)):
            for j in range(len(res[i])):
                if j==0 or j==len(res[i])-1:
                    res[i][j]=1
                elif i-1>=0 and j-1>=0:
                    res[i][j]=res[i-1][j]+res[i-1][j-1]
        return res 
        