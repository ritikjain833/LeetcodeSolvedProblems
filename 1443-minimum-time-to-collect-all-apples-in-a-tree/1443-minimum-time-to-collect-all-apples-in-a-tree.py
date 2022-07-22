class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        # edgesUsed={}
        # graph=defaultdict(list)
        # for u,v in edges:
        #     graph[u].append(v)
        #     graph[v].append(u)
        # def dfs(i):
        #     visited[i]=True
        #     for out in graph[src]:
        #         if visited[out]==False:
        #             dfs(out)
        # dfs(0)
#         g = collections.defaultdict(list)
#         seen = set()
        
#         for u,v in edges:
#             g[u].append(v)
#         stack=[]
#         stack.append(0)
#         visited=[False]*(n)
#         ans=0
#         while stack:
#             aux=stack.pop()
#             visited[aux]=True
#             for out in g[aux]:
#                 if visited[out]==False:
#                     stack.append(out)
#                 if hasApple[out]==True:
#                     ans+=2
#         return ans        
#         def dfs(node):
#             seen.add(node)
#             res = 0
            
#             for nei in g[node]:
#                 if nei not in seen:
#                     res+= dfs(nei)
            
#             if ( res>0 or hasApple[node]) and node!=0:
#                 res+=2
            
#             return res
        
       
            
        # return dfs(0)
        hasApple[0], degree = True, [0] * n
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            degree[u] += 1
            degree[v] += 1
        queue = collections.deque(v for v in range(n) if degree[v] == 1)
        while queue:
            u = queue.popleft()
            if hasApple[u]: continue
            for v in graph[u]:
                if degree[v] > 0:
                    degree[v] -= 1
                    degree[u] -= 1
                    if degree[v] == 1:
                        queue.append(v)
        print(degree)                
        return sum(degree)
        
        
        