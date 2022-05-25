from bisect import bisect_left

class Solution:
       
    def maxEnvelopes(self, arr: List[List[int]]) -> int:
        arr.sort(key=lambda x:(x[0],-x[1]))
        temp=[arr[0][1]]
        n=len(arr)
        for i in range(1,n):
            if arr[i][1]>temp[-1]:
                temp.append(arr[i][1])
            else:
                index=bisect_left(temp,arr[i][1])
                temp[index]=arr[i][1]
        return len(temp)        
            
        