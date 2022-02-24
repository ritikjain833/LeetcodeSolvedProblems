# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    #merge two sorted list 
    def merge(self,l1,l2):
        dummy=current=ListNode(0)
        while l1 and l2:
            if l1.val<l2.val:
                current.next=l1
                l1=l1.next
            else:
                current.next=l2
                l2=l2.next
            current=current.next
        current.next=l1 or l2
        return dummy.next
    #use slow and fast pointer approach to find the middle element.  
    def getmid(self,head):
        midprev=None
        while head and head.next:
            if midprev==None:
                midprev=head
            else:
                midprev=midprev.next
            head=head.next.next
        mid=midprev.next
        midprev.next=None
        return mid
        
        
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        #find the middle element
        mid=self.getmid(head)
        #sort indiviual sublist and then merge
        left=self.sortList(head)
        right=self.sortList(mid)
        return self.merge(left,right)
            
            
            
            
        
