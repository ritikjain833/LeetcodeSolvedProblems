class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x:(x[1],x[0]))
        #print(courses)
        total_time=0
        i=0
        n=len(courses)
        count=0
        heap=[]
        while i<n:
            if courses[i][0]+total_time<=courses[i][1]:
                total_time+=courses[i][0]
                count+=1
                heapq.heappush(heap,-1*courses[i][0])
            else:
                if len(heap) and (-1*heap[0])>courses[i][0]:
                    #aux=total_time-(-1*heapq.heappop(heap))
                    total_time-=(-1*heapq.heappop(heap)-courses[i][0])
                    heapq.heappush(heap,-1*courses[i][0])
                    
            i+=1    
        return count    
                
        