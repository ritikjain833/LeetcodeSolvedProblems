# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low=1
        high=n
        while low<high:
            mid=(low+high)//2
            aux=isBadVersion(mid)
            if aux==True:
                high=mid
            elif aux==False:
                low=mid+1
        return high       
            
            
        