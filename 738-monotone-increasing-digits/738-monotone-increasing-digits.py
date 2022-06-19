"""Brute force solution will be TLE since n=10^9"""
# class Solution:
#     def check(self,num):
#         aux=num
#         temp=aux%10
#         aux=aux//10
#         while aux:
#             new_temp=aux%10
#             if new_temp>temp:
                
#                 return False
#             aux=aux//10
#             temp=new_temp
#         return True    
            
#     def monotoneIncreasingDigits(self, n: int) -> int:
#         if n==0 or n==1 or n//10==0:
#             return n
#         final=float("-inf")
#         for i in range(1,n+1):
#             if self.check(i)==True:
#                 final=max(final,i)
#         return final        
class Solution:
    
    def monotoneIncreasingDigits(self,n: int) -> int:
        if n==0 or n==1 or n//10==0:
            return n
        ans= [int(x) for x in str(n)]
        ending=len(ans)-1
        for i in range(len(ans)-1,0,-1):
            if ans[i]<ans[i-1]:
                ending=i-1
                ans[i-1]-=1
        for i in range(ending+1,len(ans)):
            ans[i]=9
        final=0
        for i in range(len(ans)):
            final=final*10+ans[i]
        return final    
                
            
        

            
        