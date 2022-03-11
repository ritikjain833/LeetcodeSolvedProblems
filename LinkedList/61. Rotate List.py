# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def printList(self,head):
        aux=head
        while aux:
            print(aux.val)
            aux=aux.next
               
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        n=1
        tail=head
        while tail.next:
            n+=1
            tail=tail.next
        #find where newhead will start as same as found in rotate array n-k position    
        new_index=(n-k)%n
        #create circular linkedlist
        tail.next=head
        for i in range(new_index):
            tail=tail.next
        head=tail.next
        #set last next value to None
        tail.next=None
        return head
            
        
        
        
