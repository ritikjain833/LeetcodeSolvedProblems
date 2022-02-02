class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # empty list to store the indices
        ans=[]
        #m=length of s
        m=len(s)
        #n=length of p
        n=len(p)
        #corner case
        if n>m:
            return ans
        temp=Counter(p)
        start=0 
        end=0
        #create count to store the value match in the current window
        count=n
        #iterate till the end reaches the end of the string s
        while end<m:
            #using end characters 
            end_char=s[end]
            # if present in the dictionary decrease the count by 1. 
            if temp[end_char]>=1:
                count-=1
            # In dictionary , change the value corresponding to end character and increment the end    
            temp[end_char]-=1
            end+=1
            #if count==0 then we have find a substring that contains p as anagram
            if count==0:
                ans.append(start)
            #if end-start==n then use start characters and update the dictionary according to  it. and remove the start character. and increment the start by 1.    
            if end-start==n:
                start_char=s[start]
                if temp[start_char]>=0:
                    count+=1
                #update of dictionary[start].    
                temp[start_char]+=1
                start+=1
        return ans 
