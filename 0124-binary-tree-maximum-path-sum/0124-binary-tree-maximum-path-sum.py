# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans=float("-inf")
        def getmax(root):
            nonlocal ans
            if root is None:
                return 0
            gain_left=max(getmax(root.left),0)
            gain_right=max(getmax(root.right),0)
            temp=root.val+gain_left+gain_right
            ans=max(temp,ans)
            return max(gain_left,gain_right)+root.val
        getmax(root)
        
        return ans
        
        