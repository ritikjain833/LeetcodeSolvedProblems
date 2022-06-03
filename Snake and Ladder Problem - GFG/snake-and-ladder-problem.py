# User function Template for Python3
from collections import defaultdict,deque
class Solution:
    def bfs(self,graph,src,dest):
        queue=deque()
        visited=[0]*(31)
        visited[0]=True
        queue.append((src,0))
        while queue:
            aux,dist=queue.popleft()
            for d in graph[aux]:
                if visited[d]==False:
                    if d==dest:
                        return dist+1
                    queue.append((d,dist+1))
                    visited[d]=True
                
    def minThrow(self, n, arr):
        # code here
        ladders=[]
        snakes=[]
        for i in range(0,2*n-1,2):
            if arr[i]<arr[i+1]:
                ladders.append((arr[i],arr[i+1]))
            else:
                #print(1)
                snakes.append((arr[i],arr[i+1]))
        board=[0]*(37)
        for s,d in snakes:
            board[s]=d-s
        for s,d in ladders:
            board[s]=d-s

        graph=defaultdict(list)
        for i in range(1,30,1):
            for dice in range(1,7,1):
                v=dice+i
                v+=board[v]
                if v<=30:
                    graph[i].append(v)
        return self.bfs(graph,1,30)            

#{ 
#  Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for i in range(2*N):
            arr[i] = int(arr[i])
        
        ob = Solution()
        print(ob.minThrow(N, arr))
# } Driver Code Ends