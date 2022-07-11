# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue=deque()
        ans=[]
        if not root:
            return []
        queue.append(root)
        while queue:
            n=len(queue)
            for i in range(n):
                aux=queue.popleft()
                if aux.left:
                    queue.append(aux.left)
                if aux.right:
                    queue.append(aux.right)
                if i==n-1:
                    ans.append(aux.val)

        return ans            
        