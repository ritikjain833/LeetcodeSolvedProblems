class Solution:
    def minOperationsToFlip(self, expression: str) -> int:
        stack=[]
        stack.append([0,0,None])
        for e in expression:
            if e=="(":
                stack.append([0,0,None])
            elif e in [")","0","1"]:
                if e==")":
                    dp0,dp1,_=stack[-1]
                    stack.pop()
                else:
                    dp0,dp1=int(e!="0"),int(e!="1")
                if stack[-1][2]==None:
                    stack[-1]=[dp0,dp1,None]
                elif stack[-1][2]=="&":
                    stack[-1]=[min(dp0,stack[-1][0]),min(dp1+stack[-1][1],1+min(dp1,stack[-1][1])),None]
                else:
                    stack[-1]=[min(stack[-1][0] + dp0, min(stack[-1][0], dp0) + 1), min(dp1,stack[-1][1]),None]
            elif e in ["&",'|']:
                stack[-1][2]=e
        return max(stack[0][0], stack[0][1])        
                
                    
        