class Solution:
    def dfs(self,src,visited,rooms):
        visited[src]=True
        for nbr in rooms[src]:
            if visited[nbr]==False:
                self.dfs(nbr,visited,rooms)
                
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n=len(rooms)
        visited=[False]*(n)
        self.dfs(0,visited,rooms)
        for i in range(n):
            if visited[i]==False:
                return False
        return True    