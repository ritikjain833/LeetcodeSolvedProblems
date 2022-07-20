class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n=len(arr)
        if n<3:
            return 0
        prefix=[0]*(n)
        suffix=[0]*(n)
        prefix[0]=1
        count=1
        for i in range(1,n):
            if arr[i]>arr[i-1]:
                count+=1
            else:
                count=1
            prefix[i]=count
        suffix[n-1]=1
        count=1
        for i in range(n-2,-1,-1):
            if arr[i+1]<arr[i]:
                count+=1
            else:
                count=1
            suffix[i]=count
        ans=0
        #print(prefix)
        #print(suffix)
        for i in range(n):
            if prefix[i]!=1 and suffix[i]!=1: 
                ans=max(ans,suffix[i]+prefix[i]-1)
        return ans    
            