class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates=sorted(list(set(candidates)))
        ans=[]
        temp=[]
        def find(arr,target,temp,index):
            if len(arr)==index:
                if target==0:
                    ans.append(list(temp))
                return 
        
            if target-arr[index]>=0:
                temp.append(arr[index])
                find(arr,target-arr[index],temp,index)
                temp.pop()
            find(arr,target,temp,index+1)    
                
        find(candidates,target,temp,0)
        return ans
        
