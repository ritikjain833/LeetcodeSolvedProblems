# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        head1=dummy1=ListNode(0)
        head2=dummy2=ListNode(0)
        while head:
            if head.val<x:
                head1.next=head
                head1=head1.next
            else:
                head2.next=head
                head2=head2.next
            head=head.next
        head2.next=None
        head1.next=dummy2.next
        return dummy1.next
        