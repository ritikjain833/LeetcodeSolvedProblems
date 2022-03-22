class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans=[]
        for i in range(n):
            ans.append(1)
            k-=1
        for i in range(n-1,-1,-1):
            if k<=25:
                ans[i]+=k
                break
            else:
                ans[i]+=25
                k-=25
        final=[]
        for i in range(n):
            final.append(chr(ans[i]+96))
        return "".join(final)    
                
            
        
