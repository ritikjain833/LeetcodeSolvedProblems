# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root,maxi):
        if root:
            left=self.dfs(root.left,maxi)
            right=self.dfs(root.right,maxi)
            self.maxi=max(self.maxi,left+right+2)
            return 1+max(left,right)
        else:
            return -1
            
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxi=0
        aux=self.dfs(root,self.maxi)
        return self.maxi