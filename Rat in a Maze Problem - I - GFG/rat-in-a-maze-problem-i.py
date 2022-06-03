#User function Template for python3

class Solution:
    def valid(self,row,col,m,n):
        if row>=0 and row<n and col>=0 and col<n and m[row][col]==1:
            return True
        return False    
    def backtrack(self,m,n,directions,i,j,aux,ans):
        if i==n-1 and j==n-1:
            
            ans.append(aux)
            return
        for dr,dc,di in directions:
            r=i+dr
            c=j+dc
            if self.valid(r,c,m,n):
                m[r][c]=2
                self.backtrack(m,n,directions,r,c,aux+di,ans)
                m[r][c]=1
            #return False    
                
            
        
                     
            
    def findPath(self, m, n):
        if m[0][0]==0 or m[-1][-1]==0:
            return []
        aux=[[0]*(n) for _ in range(n)]
        directions=[[0,1,"R"],[1,0,"D"],[-1,0,"U"],[0,-1,"L"]]
        ans=[]
        if m[0][0]==1:
            m[0][0]=2
            self.backtrack(m,n,directions,0,0,"",ans)
        return sorted(ans)
        
                        
            
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        
        matrix = [[0 for i in range(n[0])]for j in range(n[0])]
        k=0
        for i in range(n[0]):
            for j in range(n[0]):
                matrix[i][j] = arr[k]
                k+=1
        ob = Solution()
        result = ob.findPath(matrix, n[0])
        result.sort()
        if len(result) == 0 :
            print(-1)
        else:
            for x in result:
                print(x,end = " ")
            print()
# } Driver Code Ends