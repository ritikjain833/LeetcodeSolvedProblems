class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """First step graph construction"""
        graph=defaultdict(list)
        # maintain degree
        degree=[0]*(numCourses)
        for i,j in prerequisites:
            graph[j].append(i)
            degree[i]+=1
        """BFS approach using indegree"""
        queue=deque()
        for i in range(numCourses):
            if degree[i]==0:
                queue.append(i)
        while queue:
            front=queue.popleft()
            for out in graph[front]:
                degree[out]-=1
                if degree[out]==0:
                    queue.append(out)
        if sum(degree)==0:
            return True
        else:
            return False
            
        