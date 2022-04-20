# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack=[]
        curr=root
        ans=[]
        while stack or curr:
            while curr:
                stack.append(curr)
                curr=curr.left
            aux=stack.pop()
            ans.append(aux.val)
            curr=aux.right
        return ans    
        