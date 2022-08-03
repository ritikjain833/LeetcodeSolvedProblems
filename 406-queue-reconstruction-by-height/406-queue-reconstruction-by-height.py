class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # sort by decreasing height and if height is equal then compare by the number of people increasing
        #It will ensure that for largest people exact k people infront.
        
        people.sort(key=lambda p: (-p[0], p[1]))
        #print(people)
        res = []
        for p in people:
            res.insert(p[1], p)
        return res
        