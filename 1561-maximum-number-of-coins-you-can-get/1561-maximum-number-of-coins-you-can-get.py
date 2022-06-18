class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort(reverse=True)
        i=0
        j=1
        n=len(piles)
        k=n-1
        sum1=0
        while j<k:
            sum1+=piles[j]
            i+=2
            j+=2
            k-=1
            
        return sum1