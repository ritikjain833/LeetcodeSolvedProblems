class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        #sort by attack in ascending order and defense in descending order
        properties.sort(key=lambda x:(-x[0],x[1]))
        #ans=0
        weak=0
        #max_defense=0 
        max_defense=0
        
        for x,defense in properties:
            if defense<max_defense:
                weak+=1
            else:
                max_defense=defense
        return weak        
            
            
        