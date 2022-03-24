# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        queue=deque()
        if not root:
            return []
        queue.append(root)
        ans=[]
        while queue:
            temp=float("-inf")
            n=len(queue)
            for i in range(n):
                aux=queue.popleft()
                temp=max(temp,aux.val)
                if aux.left:
                    queue.append(aux.left)
                if aux.right:
                    queue.append(aux.right)
            ans.append(temp)
        return ans    
        