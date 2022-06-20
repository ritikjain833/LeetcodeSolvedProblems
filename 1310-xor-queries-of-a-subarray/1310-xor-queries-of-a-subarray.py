class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n=len(arr)
        ans=[0]*(n)
        ans[0]=arr[0]
        for i in range(1,n):
            ans[i]=ans[i-1]^arr[i]
        res=[]
        for i,j in queries:
            if i==0:
                res.append(ans[j])
            else:
                res.append(ans[j]^ans[i-1])
        return res        
            
        
        