from sortedcontainers import SortedList
class NumberContainers:

    def __init__(self):
        self.dict={}
        self.mp=defaultdict(SortedList)
        

    def change(self, index: int, number: int) -> None:
        if index in self.dict:
            old=self.dict[index]
            self.mp[old].discard(index)
            if len(self.mp[old])==0:
                del self.mp[old]
        self.dict[index]=number
        #self.mp[number].remove(index)
        self.mp[number].add(index)

    def find(self, number: int) -> int:
        if number in self.mp:
            return self.mp[number][0]
        return -1
        


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)