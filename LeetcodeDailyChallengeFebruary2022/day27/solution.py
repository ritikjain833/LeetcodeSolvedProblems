# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue=deque()
        if not root:
            return 0
        queue.append((root,1))
        ans=float("-inf")
        while queue:
            n=len(queue)
            left=0
            right=0
            for i in range(n):
                aux,index=queue.popleft()
                if i==0:
                    left=index
                if i==n-1:
                    right=index
                if aux.left:
                    queue.append((aux.left,2*index))
                
                if aux.right:
                    queue.append((aux.right,2*index+1)) 
                 
            ans=max(ans,right-left+1)
        return ans        
                
                    
                
                
                    
                
        
        
