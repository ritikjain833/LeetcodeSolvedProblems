# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self,root,ans):
        if root:
            self.inorder(root.left,ans)
            ans.append(root.val)
            self.inorder(root.right,ans)
    def increasingBST(self, root: TreeNode) -> TreeNode:
        ans=[]
        
        self.inorder(root,ans)
        temp=curr=TreeNode(None)
        for v in ans:
            curr.right=TreeNode(v)
            curr=curr.right
        return temp.right 