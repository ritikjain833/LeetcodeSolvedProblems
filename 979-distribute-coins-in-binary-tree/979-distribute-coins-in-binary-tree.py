# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def post_order(self,root):
        if not root:
            return 0
        left=self.post_order(root.left)
        right=self.post_order(root.right)
        self.ans+=abs(left)+abs(right)
        return root.val+left+right-1
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        self.post_order(root)
        return self.ans
        