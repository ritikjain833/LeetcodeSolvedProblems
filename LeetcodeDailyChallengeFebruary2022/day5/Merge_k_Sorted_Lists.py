import heapq
#using priorty queue for comparison
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        #generally heapq uses <=
        #Tuples are compared position by position: the first item of the first tuple is compared to the first item of the second tuple; if they are not equal (i.e. the first is greater or smaller than the second) then that's the result of the comparison, else the second item is considered, then the third and so on.
        #that's why index is used for generating unique values
        #using list first value as the key as it is in sorted order.
        h = [(head.val, index, head) for index, head in enumerate(lists) if head ]
        heapq.heapify(h)
        dummy = ListNode()
        last = dummy
        while h:
            val, index, node = heapq.heappop(h)
            last.next=ListNode(val)
            last=last.next
            node=node.next
            if node:
                #pushing the next node.val in the heap
                heapq.heappush(h, (node.val, index, node))
        return dummy.next
