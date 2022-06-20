# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow=head
        fast=head
        if head is None or head.next is None:
            return None
            
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        #print(slow.val) 
        start=head
        while start.next!=slow:
            start=start.next
        start.next=start.next.next
        return head
        