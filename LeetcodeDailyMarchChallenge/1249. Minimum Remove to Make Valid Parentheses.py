class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack=[]
        S=list(s)
        #iterate over S in list and find any opening bracket then append its index to stack 
        for i,c in enumerate(S):
            
            if c==")":
                #if any "(" is found in the stack remove that"
                if len(stack)>0:
                    stack.pop()
                else:
                #change that character to empty character    
                    S[i]=""
            elif c=="(":
                #append index value
                stack.append(i)
        #if anything is found in the stack remove that value at that index to be empty.        
        for i in stack:
            S[i]=""
        #return the jointed string obtained    
        return "".join(S)    
                
                
                
                    
               
