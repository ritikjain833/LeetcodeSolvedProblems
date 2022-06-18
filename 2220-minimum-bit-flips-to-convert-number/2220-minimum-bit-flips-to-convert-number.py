class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        aux=start^goal
        count=0
        while aux:
            temp=aux%2
            if temp&1==1:
                count+=1
            aux=aux//2
        return count    
        