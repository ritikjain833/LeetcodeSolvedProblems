class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n=len(nums)
        max_possible=2**maximumBit-1
        #print(max_possible)
        ans=[0]*(n)
        temp_or=0
        for i in range(n):
            temp_or=temp_or^nums[i]
        ans[0]=temp_or
        j=n-1
        i=1
        while i<n:
            temp_or=temp_or^nums[j]
            ans[i]=temp_or
            j-=1
            i+=1
        for i in range(n):
            ans[i]=ans[i]^max_possible
        return ans    
            
        