# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        count1=0
        nodeA=headA
        while nodeA:
            count1+=1
            nodeA=nodeA.next
        count2=0
        nodeB=headB
        while nodeB:
            count2+=1
            nodeB=nodeB.next
        if count1>=count2:
            diff=count1-count2
            auxA=headA
            while diff:
                auxA=auxA.next
                diff-=1
            aux2=headB
            while aux2:
                if aux2==auxA:
                    return aux2
                else:
                    aux2=aux2.next
                    auxA=auxA.next
        else:
            diff=count2-count1
            auxB=headB
            while diff:
                auxB=auxB.next
                diff-=1
            aux1=headA
            while aux1:
                if aux1==auxB:
                    return aux1
                else:
                    aux1=aux1.next
                    auxB=auxB.next
        return None            
                    
                
                
        