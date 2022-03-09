# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        queue=deque()
        ans=[]
        
        queue.append(root)
        while queue:
            n=len(queue)
            aux=[]
            for i in range(n):
                tem=queue.popleft()
                #print(tem.val)
                aux.append(tem.val)
                if tem.left:
                    queue.append(tem.left)
                if tem.right:
                    queue.append(tem.right)
            ans.append(aux)
        return ans    
                 
        
