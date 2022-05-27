class Solution:
    def numOfWays(self, n: int) -> int:
        mod=10**9+7
        s=6
        t=6
        for i in range(2,n+1):
            aux=s
            s=(2*s+2*t)%mod
            
            t=(3*t+2*aux)%mod
        return (s+t)%mod