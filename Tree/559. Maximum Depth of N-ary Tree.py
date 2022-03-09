"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
from collections import deque
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        queue=deque()
        queue.append([root,1])
        ans=1
        while queue:
            n=len(queue)
            for i in range(n):
                aux,level=queue.popleft()
                new=len(aux.children)
                for j in range(new):
                    queue.append([aux.children[j],level+1])
                ans=max(ans,level)
        return ans        
                    
        
        
