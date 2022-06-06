class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        aux=[0]*(1001)
        for i,j,k in trips:
            for a in range(j,k):
                aux[a]+=i
        for i in range(1001):
            if aux[i]>capacity:
                return False
        return True    
        