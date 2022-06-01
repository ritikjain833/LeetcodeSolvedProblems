class MinStack:

    def __init__(self):
        
        self.stack=[]
        
        

    def push(self, val: int) -> None:
        current_min=self.getMin()
        
        if current_min is None or val<current_min:
            current_min=val
        self.stack.append((val,current_min))
        
        
        
        

    def pop(self) -> None:
        return self.stack.pop()
        
        

    def top(self) -> int:
        return self.stack[len(self.stack)-1][0]
    
        

    def getMin(self) -> int:
        if len(self.stack)==0:
            return None
        return self.stack[len(self.stack)-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()