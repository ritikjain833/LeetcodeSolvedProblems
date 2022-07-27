# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#from collections import deque
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # ans=[]
        # if not root:
        #     return root
        # def dfs(head):
        #     if head:
        #         ans.append(head.val)
        #         dfs(head.left)
        #         dfs(head.right)
        # head=root        
        # dfs(head)
        # root=TreeNode(ans[0])
        # for i in range(1,len(ans)):
        #     root.right=TreeNode(ans[i])
        #     #print(root.right.val)
        #     root=root.right
        if not root:
            return root
        stack=[]
        stack.append(root)
        while stack:
            aux=stack.pop()
            if aux.right:
                stack.append(aux.right)
            if aux.left:
                stack.append(aux.left)
            if stack:    
                aux.right=stack[-1]
                aux.left=None
            
        
            
        
         
           
            
        
        