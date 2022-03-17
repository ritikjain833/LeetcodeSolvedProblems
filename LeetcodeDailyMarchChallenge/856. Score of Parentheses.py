class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack=[]
        stack.append(0)
        for i in range(len(s)):
            if s[i]=="(":
                stack.append(0)
            else:
                aux=stack.pop()
                stack[-1]+=max(2*aux,1)
        return stack[-1]        
                
        
