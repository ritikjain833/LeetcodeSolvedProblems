class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:(x[0],-x[1]))
        size = len(intervals)
        l1 = intervals[0][0]
        r1 = intervals[0][1]
        count=size
        for i in range(1, size):
            l2=intervals[i][0]
            r2=intervals[i][1]
            if r1>=r2:
                count-=1
            r1=max(r1,r2)
        return count
                
                
        
