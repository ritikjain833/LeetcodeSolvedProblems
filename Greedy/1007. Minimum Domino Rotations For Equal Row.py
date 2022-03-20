class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        d1=Counter(tops)
        d2=Counter(bottoms)
        max_top=0
        temp1=float('-inf')
        temp2=float("-inf")
        for key,val in d1.items():
            if val>=temp1:
                temp1=val
                max_top=key
        max_bottom=float('-inf')
        for key,val in d2.items():
            if val>=temp2:
                temp2=val
                max_bottom=key
        #print(max_top,max_bottom)
        count1=0
        flag1=True
        for first,second in zip(tops,bottoms):
            if first!=max_top and second==max_top:
                count1+=1
            elif first!=max_top and second!=max_top:
                flag1=False
                break
        flag2=True
        count2=0
        for first,second in zip(tops,bottoms):
            if second!=max_bottom and first==max_bottom:
                count2+=1
            elif second!=max_bottom and first!=max_bottom:
                flag2=False
                break
        if flag1 or flag2:
            return min(count1,count2)
        else:
            return -1
            
        
        
