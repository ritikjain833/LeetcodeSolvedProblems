class Solution:
    def isPossible(self, target: List[int]) -> bool:
        heap=[]
        #target.sort()
        
        heap=[-x for x in target]
        
        heapify(heap)
        #print(heap)
        n=len(target)
        total=sum(target)
        while heap:
            aux=-1*heapq.heappop(heap)
            total-=aux
            #print(aux,total)
            """ aux==1 handles the normal cases 
            while total==1 handles the case like 1,large_num"""
            
            if aux==1 or total==1:
                return True
            """
            here total represents current_sum and largest number is always more than the remaining element sum 
            
            if remaining_sum>largest_element we can not find the answer then and current_sum(total) is zero 
            """
            if aux<=total or total==0 or aux%total==0:
                return False
            """ avoides the repititve step like 10,3 7,3 4,3 1,3 to directly 1,3"""
            aux=aux%total
            #adding the number again 
            total+=aux    
            #inserting into the heap again
            heapq.heappush(heap,-1*aux) 
            
            
            