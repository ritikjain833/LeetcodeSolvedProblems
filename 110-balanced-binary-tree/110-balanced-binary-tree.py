# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#Time complexity is O(n)
#One whole traversal is required.
#space complexity is O(n)
class Solution:
    def dfs(self,root):
        if root:
            left=self.dfs(root.left)
            right=self.dfs(root.right)
            balanced=left[0] and right[0] and abs(left[1]-right[1])<=1
            if balanced==False:
                return [False]
            return  [balanced,1+max(left[1],right[1])]
        else:
            return [True,0]
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root)[0]
            
        
        