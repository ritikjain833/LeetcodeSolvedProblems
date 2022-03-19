class FreqStack:

    def __init__(self):
        self.map=collections.Counter()
        self.maxfreq=0
        self.m=collections.defaultdict(list)
        

    def push(self, val: int) -> None:
        self.map[val]+=1
        
        if self.map[val]>self.maxfreq:
            self.maxfreq=self.map[val]    
        self.m[self.map[val]].append(val)
        

    def pop(self) -> int:
        aux=self.m[self.maxfreq].pop()
        if not self.m[self.maxfreq]:
            self.maxfreq-=1
        self.map[aux]-=1
        return aux
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
