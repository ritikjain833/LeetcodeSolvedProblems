class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        mp=dict()
        for i in arr:
            if i not in mp:
                mp[i]=1
            else:
                mp[i]+=1
        mp=dict(sorted(mp.items(), key=lambda item: -item[1]))
        count=0
        ans=0
        for i,j in mp.items():
            count+=j
            ans+=1
            if count>=(len(arr)//2):
                break
                
        return ans
        