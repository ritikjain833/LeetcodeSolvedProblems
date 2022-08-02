import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        minHeap=[]
        for i in range(min(k,len(matrix))):
            heapq.heappush(minHeap,(matrix[i][0],0,matrix[i]))
        count=0
        number=0
        while minHeap:
            number,i,row=heapq.heappop(minHeap)
            count+=1
            if count==k:
                break
            if len(row)>i+1:
                heapq.heappush(minHeap,(row[i+1],i+1,row))
        return number 
        