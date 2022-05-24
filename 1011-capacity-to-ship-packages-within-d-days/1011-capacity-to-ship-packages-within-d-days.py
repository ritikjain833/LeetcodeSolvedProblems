class Solution:
    def check(self,weights,mid):
        count=0
        sum1=0
        for i in range(len(weights)):
            sum1+=weights[i]
            if sum1>mid:
                count+=1
                sum1=weights[i]
        return count+1      
            
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low=max(weights)
        high=sum(weights)
        while low<high:
            mid=(low+high)//2
            #print(mid)
            #print(self.check(weights,mid))
            if self.check(weights,mid)<=days:
                high=mid
            else:
                low=mid+1
        return low      