# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self,head):
        curr=head
        prev=None
        while curr:
            nex=curr.next
            curr.next=prev
            prev=curr
            curr=nex
        return prev    
        
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy=ListNode(0)
        dummy.next=head
        aux=dummy
        count=0
        while count+1<left:
            aux=aux.next
            count+=1
        start=aux.next
        temp=aux
        while count<right:
            temp=temp.next
            count+=1
        end=temp.next    
        temp.next=None 
        new_head=self.reverse(start)
        aux.next=new_head
        start.next=end
        return dummy.next
           
            
        