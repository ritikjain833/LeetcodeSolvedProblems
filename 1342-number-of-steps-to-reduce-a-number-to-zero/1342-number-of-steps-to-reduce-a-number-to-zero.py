class Solution:
    def numberOfSteps(self, num: int) -> int:
        count=0
        while num>0:
            if num&1:
                num-=1
            else:
                num=num//2
            count+=1
        return count    
        