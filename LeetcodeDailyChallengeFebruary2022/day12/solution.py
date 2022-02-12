from collections import deque
class Solution:
    def ladderLength(self, begin: str, end: str, word: List[str]) -> int:
        #idea is to use the concept of bfs append every string that differs by one position change from previous string in the queue.
        #example
        #"hit"
        # "cog"
        # ["bit","hot","hog","cog"]
        # append begin in the beginning with distance equal to 1
        # in the first step there are two strings that differ by one position from the begin (bit,hot) and now distance is 2.
        # in the second step there is only one string that differs by one position . (hog) and distance is 3.
        #in the third step there is only string that differs by one position .(cog) and distance now is 4.
        # in the queue front ==end:  stop here and return the distance
        
        if end not in word:
            return 0
        word=set(word)
        q=deque()
        q.append((begin,1))
        while q:
            temp,dist=q.popleft()
            if temp==end:
                return dist
            n=len(temp)
            
            for i in range(n):
                for char in "abcdefghijklmnopqrstuvwxyz":
                    new=temp[:i]+char+temp[i+1:]
                    if new in word:
                        q.append((new,dist+1))
                        word.remove(new)            
        return 0                
        
        
        
        
        
        
