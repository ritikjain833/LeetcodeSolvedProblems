# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # base cases when head is None and list contains single element
        if head is None or head.next is None:
            return head
        #current pointer
        #previos pointer that stores unique values upto that point
        curr=head
        prev=None
        #iterating till and current
        while curr and curr.next:
            #if curr and curr.next values are same 
            if curr.val==curr.next.val:
                #iteratr till values are same
                while curr.next and curr.val==curr.next.val:
                    curr=curr.next
                #change head position if prev is None ro new unique value     
                if prev==None:
                    head=curr.next
                #change the value of prev.next to the new unique value    
                else:
                    prev.next=curr.next
                curr=curr.next
            #just iterate and change the previous and current pointer    
            else:
                prev=curr
                curr=curr.next
        return head        
                    
        
        
            
            

                
    
                
                    
                    
        
