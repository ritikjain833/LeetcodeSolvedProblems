class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        #current_fuel=0
        max_reach=startFuel
        for i,j in stations:
            if max_reach<i:
                return -1
            max_reach+=j
        dp=[startFuel]+[0]*(len(stations))
        for i,(position,fuel) in enumerate(stations):
            for t in range(i,-1,-1):
                if dp[t]>=position:
                    dp[t+1]=max(dp[t+1],dp[t]+fuel)
        for i,d in enumerate(dp):
            if d>=target:
                return i   
        return -1    
            
        