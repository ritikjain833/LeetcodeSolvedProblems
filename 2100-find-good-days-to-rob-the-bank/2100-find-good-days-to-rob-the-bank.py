class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        
        ans=[]
        n=len(security)
        decreasing=[0]*(n)
        increasing=[0]*(n)
        count=1
        decreasing[0]=1
        for i in range(1,n):
            if security[i-1]>=security[i]:
                count+=1
            else:
                count=1
            decreasing[i]=count
        increasing[n-1]=1
        count=1
        for i in range(n-2,-1,-1):
            if security[i+1]>=security[i]:
                count+=1
            else:
                count=1
            increasing[i]=count
        for i in range(time,n-time):
            if decreasing[i]-1>=time and increasing[i]-1>=time:
                ans.append(i)
        return ans        
        