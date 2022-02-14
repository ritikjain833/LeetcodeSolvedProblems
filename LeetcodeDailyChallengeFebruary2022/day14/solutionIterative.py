# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        stack=[]
        stack.append((root,1))
        count=0
        while stack:
            x,val=stack.pop()
            if x.right:
                stack.append((x.right,val+1))
            if x.left:
                stack.append((x.left,val+1))
            count=max(count,val)
        return count        
            
                
            
                
            
        
