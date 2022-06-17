# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root,ans):
        if root:
            self.dfs(root.left,ans)
            ans.append(root.val)
            self.dfs(root.right,ans)
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        ans=[]
        self.dfs(root,ans)
        ans.sort()
        for i in range(len(ans)-1):
            if ans[i]!=ans[i+1]:
                return ans[i+1]
        return -1    
                
        
            
        