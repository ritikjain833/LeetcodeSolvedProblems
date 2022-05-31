class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        ans=[]
        def dfs(i):
            if i>=len(nums):
                res.append(ans.copy())
                return
            for j in range(i,len(nums)):
                ans.append(nums[j])
                dfs(j+1)
                ans.pop()
            dfs(j+1)
        dfs(0)
        return res
        