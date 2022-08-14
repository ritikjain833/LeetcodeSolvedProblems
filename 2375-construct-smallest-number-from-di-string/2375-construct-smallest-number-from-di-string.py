class Solution:
    def smallestNumber(self, pattern: str) -> str:
        count=1
        
        ans=[]
        ans.append(count)
        n=len(pattern)
        i=0
        while i<n:
            if pattern[i]=="I":
                count+=1
                ans.append(count)
                i+=1
            else:
                aux=ans.pop()
                temp=[]
                while i<n and pattern[i]!="I":
                    i+=1
                    count+=1
                    temp.append(count)
                while temp:
                    ans.append(temp.pop())
                #ans.append(count)
                ans.append(aux)
        return ''.join(map(str, ans))
        