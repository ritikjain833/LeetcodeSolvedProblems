class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        diff1=float("-inf")
        diff2=float("-inf")
        len_h=len(horizontalCuts)
        len_w=len(verticalCuts)
        mod=10**9+7
        # if len_w==1 and len_h==1:
        #     ans1=(h-horizontalCuts[0])*(w-verticalCuts[0])
        #     ans2=(horizontalCuts[0])*(verticalCuts[0])
        #     ans3=(h-horizontalCuts[0])*verticalCuts[0]
        #     ans4=horizontalCuts[0]*(w-verticalCuts[0])
        #     return max(ans1,max(ans2,max(ans3,ans4)))%mod
        # if len_h==1:
        #     diff1=max(h-horizontalCuts[0],horizontalCuts[0])
        # if len_w==1:
        #     diff2=max(w-verticalCuts[0],verticalCuts[0])
            

        for i in range(1,len_h):
            current_diff=horizontalCuts[i]-horizontalCuts[i-1]
            diff1=max(diff1,current_diff)
        diff1=max(diff1,h-horizontalCuts[-1])
        diff1=max(diff1,horizontalCuts[0])
        #print(diff1)
        for i in range(1,len_w):
            current_diff=verticalCuts[i]-verticalCuts[i-1]
            diff2=max(diff2,current_diff)
        diff2=max(diff2,w-verticalCuts[-1])   
        #print(diff2)
        diff2=max(diff2,verticalCuts[0])
        return (diff1*diff2)%mod    
        