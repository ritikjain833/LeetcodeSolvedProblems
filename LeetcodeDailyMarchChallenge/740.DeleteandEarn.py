class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        ans=[0]*(10**4+2)
        maxi=float("-inf")
        for temp in nums:
            ans[temp]+=temp
            maxi=max(maxi,ans[temp])
        # take p    
        second_last=ans[0]
        last=ans[1]
        for i in range(2,maxi+2):
            aux=max(second_last+ans[i],last)
            second_last=last
            last=aux
        return aux
        
        
