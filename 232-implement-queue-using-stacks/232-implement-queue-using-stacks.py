class MyQueue:

    def __init__(self):
        self.stack1=[]
        self.stack2=[]
        
        

    def push(self, x: int) -> None:
        self.stack1.append(x)
        

    def pop(self) -> int:
        if len(self.stack2)==0 and len(self.stack1)>0:
            while len(self.stack1):
                aux=self.stack1.pop()
                self.stack2.append(aux)
            return self.stack2.pop()
        else:
            return  self.stack2.pop()
        

    def peek(self) -> int:
        if len(self.stack2)==0:
            return self.stack1[0]
        else:
            return self.stack2[-1]
        

    def empty(self) -> bool:
        if len(self.stack2) or len(self.stack1):
            return  False
        else:
            return True
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()