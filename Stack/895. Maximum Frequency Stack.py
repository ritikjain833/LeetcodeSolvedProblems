class FreqStack:

    def __init__(self):
        # map is used to store the frequency of each element
        self.map=collections.Counter()
        # maxfreq is usd to store the maximum frequency of some element
        self.maxfreq=0
        #m is dictionary or map to store the number of elements of some frequency with lastest element at the top
        self.m=collections.defaultdict(list)
        

    def push(self, val: int) -> None:
        #increment the count of val in the map
        self.map[val]+=1
        # if the value more than maxfreq update that value.
        if self.map[val]>self.maxfreq:
            self.maxfreq=self.map[val]    
        # add element to the dictionary m for that frequency    
        self.m[self.map[val]].append(val)
        

    def pop(self) -> int:
        # pop the topmost element with the maxfreq from the dictionary m
        aux=self.m[self.maxfreq].pop()
        # if maxfreq reaches zero decrement the maxfreq value
        if self.m[self.maxfreq]==0:
            self.maxfreq-=1
        #change or decrement in the frequency map of each element.    
        self.map[aux]-=1
        #return popped element.
        return aux
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
