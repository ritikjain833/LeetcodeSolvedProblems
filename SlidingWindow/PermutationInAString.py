#Problem link: https://leetcode.com/problems/permutation-in-string/
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m=len(s1)
        n=len(s2)
        if m>n:
            return False
        has=Counter(s1)
        start=0
        end=0
        count=m
        while end<n:
            end_char=s2[end]
            if has[end_char]>=1:
                count-=1
            has[end_char]-=1
            end+=1
            if count==0:
                return True
            if end-start==m:
                start_char=s2[start]
                if has[start_char]>=0:
                    count+=1
                has[start_char]+=1
                start+=1
        return False        
            
                
            
                
        
