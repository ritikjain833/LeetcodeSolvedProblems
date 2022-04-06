class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        mod=10**9+7
        res=0
        arr.sort()
        n=len(arr)
        for i,x in enumerate(arr):
            rem=target-arr[i]
            j=i+1
            k=n-1
            while j<k:
                if arr[j]+arr[k]>rem:
                    k-=1
                elif arr[j]+arr[k]<rem:
                    j+=1
                elif arr[j]!=arr[k]:
                    l1=1
                    l2=1
                    while j+1<k and arr[j]==arr[j+1]:
                        j+=1
                        l1+=1
                    while k-1>j and arr[k]==arr[k-1]:
                        k-=1
                        l2+=1
                    res=res+(l1*l2)
                    res=res%mod
                    j+=1
                    k-=1
                else:
                    res+=((k-j)*(k-j+1))//2
                    res%=mod
                    break
        return res            
                    
                    
        