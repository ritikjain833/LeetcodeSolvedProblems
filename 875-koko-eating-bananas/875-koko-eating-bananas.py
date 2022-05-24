class Solution:
    def check(self,piles,mid):
        count=0
        for i in range(len(piles)):
            if piles[i]%mid==0:
                count+=(piles[i]//mid)
            else:
                count+=(piles[i]//mid)+1
        return count        
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low=1
        high=max(piles)
        while low<high:
            mid=(low+high)//2
            if self.check(piles,mid)>h:
                low=mid+1
            else:
                high=mid
        return low