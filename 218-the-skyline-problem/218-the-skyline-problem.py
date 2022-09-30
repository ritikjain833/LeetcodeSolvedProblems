class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for L, R, H in buildings:
            events.append((L, -H, R)) 
            # start event, using min heap so append -H
            # need that -H in the list, not just for the heap. Because, when you sort events, you want to make sure for given x an event with max H is processed first. ex: height 14 vs 15, after negative, -15 event would come before -14 event
            events.append((R, 0, 0))
        events.sort()
        
        res = [(0, 0)]
        heap = [(0, float('inf'))]
        
        for pos, negH, R in events:
            # processing events
            # 1. cleanout old events by pop out those right ends before new event
            # 2. push the new events to the queue
            # 3. check if new largest height affect result skyline
            
            # pop out building which is end
            while heap[0][1] <= pos:
                heapq.heappop(heap)
            
            # if it is a start of building, push it into heap as current building
            if negH != 0:
                heapq.heappush(heap, (negH, R))
            
            # if change in height with previous key point, append to result
            if res[-1][1] != -heap[0][0]:
                res.append([pos, -heap[0][0]])
        return res[1:]