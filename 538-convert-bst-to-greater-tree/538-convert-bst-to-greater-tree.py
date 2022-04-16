# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        temp=0
        stack=[]
        #stack.append(root)
        node=root
        while node or stack:
            while node:
                stack.append(node)
                node=node.right
            node=stack.pop()
            node.val+=temp
            temp=node.val
            node=node.left
        return root 