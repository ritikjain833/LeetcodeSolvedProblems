class MyHashSet:

    def __init__(self):
        self.lis=[False]*(10**6+1)        

    def add(self, key: int) -> None:
        self.lis[key]=True
        

    def remove(self, key: int) -> None:
        self.lis[key]=False
        

    def contains(self, key: int) -> bool:
        return self.lis[key]
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)