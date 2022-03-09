# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        queue=deque()
        queue.append([root,0])
        while queue:
            n=len(queue)
            temp=[]
            for i in range(0,n):
                aux,level=queue.popleft()
                #print(aux.val,level)
                if level%2==0:
                    if aux.val%2==0:
                        #print("value is even")
                        return False
                    else:
                        if len(temp) and aux.val<=temp[-1]:
                            #print("increasing fails")
                            return False
                        else:
                            temp.append(aux.val)
                else:
                    if aux.val%2==1:
                        #print("value is odd")
                        return False
                    else:
                        if len(temp) and aux.val>=temp[-1]:
                            #print("decreasing fails")
                            return False
                        else:
                            temp.append(aux.val)
                            
                     
                if aux.left:
                    queue.append([aux.left,level+1])
                if aux.right:
                    queue.append([aux.right,level+1])
                    
                  
        return True            
        
        
        
