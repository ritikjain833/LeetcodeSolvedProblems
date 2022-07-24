#SortedList works as ordered_set which maintains order
from sortedcontainers import SortedList
class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # create two maps 
        # one for food--> cuisine rating
        # second for cusine--> rating,food using ordered_set
        #Since we want the highest value store them as negative number.
        self.mp = {}
        self.data = defaultdict(SortedList)
        for food, cuisine, rating in zip(foods, cuisines, ratings): 
            self.mp[food] = (cuisine, rating)
            self.data[cuisine].add((-rating, food))
        

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.mp[food]
        self.mp[food] = cuisine, newRating
        self.data[cuisine].remove((-rating, food))
        self.data[cuisine].add((-newRating, food))
        

    def highestRated(self, cuisine: str) -> str:
        return self.data[cuisine][0][1]
        


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)