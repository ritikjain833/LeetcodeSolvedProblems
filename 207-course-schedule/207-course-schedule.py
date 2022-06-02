class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph=defaultdict(list)
        n=numCourses
        degree=[0]*(n)
        for j,i in prerequisites:
            graph[i].append(j)
            degree[j]+=1
        queue=deque()
        for i in range(n):
            if degree[i]==0:
                queue.append(i)
        while queue:
            aux=queue.popleft()
            for out in graph[aux]:
                degree[out]-=1
                if degree[out]==0:
                    queue.append(out)
        if sum(degree)==0:
            return True
        return False