#User function Template for python3

class Solution:
    def changeBits(self, N):
        # code here 
        bits=0
        aux=N
        while aux:
            aux=aux//2
            bits+=1
        count=bits
        res=0
        i=0
        while i<count:
            res=res|(1<<i)
            i+=1
        
            
        
        return [res-N,res]
            

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        ans = ob.changeBits(N)
        
        print(ans[0],ans[1])
# } Driver Code Ends