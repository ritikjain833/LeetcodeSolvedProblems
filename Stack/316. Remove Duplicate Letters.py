class Solution:
    def smallestSubsequence(self, s: str) -> str:
        #keep track of the last instances of each unique character.
        last_index=[0]*(26)
        n=len(s)
        #boolean array to keep track of each character
        seen=[False]*(26)
        #maintaining monotonic decreasing stack for smallest lexiographical characters. 
        stack=[]
        #iterate over string
        for i in range(n):
            last_index[ord(s[i])-ord('a')]=i
        for i in range(n):
            aux=ord(s[i])-ord("a")
            #if already seen
            if seen[aux]:
                continue
            # maintain monotonic decreasing stack and current_index is less than last index occurence.then pop out and unseen it.   
            while stack and stack[-1] >aux and i<last_index[stack[-1]]:
                seen[stack.pop()]=False
           #append the character     
            stack.append(aux)
            seen[aux]=True
        ans=[]
        while stack:
            aux=stack.pop()
            #converting numeric 0:a 1:b to english character
            ans.append(chr(aux+97))
        #reverse thr ordering for lexographic smallest    
        ans=ans[::-1]
        return "".join(ans)
                    
            
        
        
