class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        dic=Counter(nums)
        ans=[]
        for i,j in dic.items():
            if j==1:
                ans.append(i)
        return ans        
        
      
        