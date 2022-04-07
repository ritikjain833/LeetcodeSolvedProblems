import heapq as hp
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones=[-x for x in stones ]
        hp.heapify(stones)
        while len(stones)>1 and stones[0]!=0:
            hp.heappush(stones,hp.heappop(stones)-hp.heappop(stones))
        return -stones[0]    
        