# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        count=0
        
        temp1=l1
        temp2=l2
        count1=0
        count2=0
        while temp1:
            temp1=temp1.next
            count1+=1
        while temp2:
            temp2=temp2.next
            count2+=1
        if count1<count2:
            temp=l1
            l1=l2
            l2=temp
        head=l1    
        while l1 and l2:
            if count==0 and l1 and l2:
                l1.val+=l2.val
                #print(l1.val)
                if l1.val>=10:
                    l1.val=l1.val-10
                    count=1
                else:
                    count=0
                l1=l1.next
                l2=l2.next
            elif count==1 and l1 and l2:
                l1.val+=(l2.val+count)
                if l1.val>=10:
                    l1.val=l1.val-10
                    count=1
                else:
                    count=0
                l1=l1.next
                l2=l2.next
        if l2==None:
            while l1:
                if count==1:
                    l1.val+=count
                    if l1.val>=10:
                        l1.val=l1.val-10
                        count=1
                    else:
                        count=0
                l1=l1.next
        if l1==None:
            while l2:
                if count==1:
                    l1.val+=(l2.val+count)
                    if l1.val>=10:
                        l1.val-=10
                        count=1
                    else:
                        count=0
                l2=l2.next
        if count==1:         
            temp=head
            while temp.next:
                temp=temp.next

            temp.next=ListNode(1)    
        return head        
                    
            
            
            
        
