"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        newNode = Node(node.val,[])
        dic={node:newNode}
        stack = [node]
        while stack:
            node = stack.pop()
            for neigh in node.neighbors:
                if neigh not in dic:
                    stack.append(neigh)
                    newNeighbor=Node(neigh.val,[])
                    dic[neigh]=newNeighbor
                    dic[node].neighbors.append(newNeighbor)
                    
                else:    
                    dic[node].neighbors.append(dic[neigh])
        return newNode            
             
                    
        
        
