class MyHashMap:

    def __init__(self):
        self.lis=[-1]*(10**6+1)
        

    def put(self, key: int, value: int) -> None:
        self.lis[key]=value
        

    def get(self, key: int) -> int:
        if self.lis[key]!=-1:
            return self.lis[key]
        else:
            return -1
        

    def remove(self, key: int) -> None:
        self.lis[key]=-1
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)