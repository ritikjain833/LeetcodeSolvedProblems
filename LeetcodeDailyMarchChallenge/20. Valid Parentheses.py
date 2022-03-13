class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        temp=["(","{","["]
        for i in s:
            if i in temp:
                stack.append(i)
            if i=="}" and stack and stack[-1]=="{":
                stack.pop()
            elif i=="}":
                stack.append(i)
            if i=="]" and stack and stack[-1]=="[":
                stack.pop()
            elif i=="]":
                stack.append(i)
            if i==")" and stack and stack[-1]=="(":
                stack.pop()
            elif i==")":
                stack.append(i)
                
        if len(stack)==0:
            return True
        return False
                
            
        
