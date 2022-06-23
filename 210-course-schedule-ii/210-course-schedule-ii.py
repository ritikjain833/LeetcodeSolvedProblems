class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph=defaultdict(list)
        degree=[0]*(numCourses)
        for i,j in prerequisites:
            graph[j].append(i)
            degree[i]+=1
        queue=deque()    
        ordering=[]
        for i in range(numCourses):
            if degree[i]==0:
                queue.append(i)
                ordering.append(i)
        while queue:
            front=queue.popleft()
            for out in graph[front]:
                degree[out]-=1
                if degree[out]==0:
                    queue.append(out)
                    ordering.append(out)
        if sum(degree)==0:
            return ordering
        else:
            return []
        
        