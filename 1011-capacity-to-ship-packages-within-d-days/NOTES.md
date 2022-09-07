use the concept of binary search here.
Think of the lower bound and upper bound of the binary search.
​
lower_bound=max(arr) when days>=n
upper_bound=sum(arr) when days ==1
​
if for a particular case it can be solved then we can infer that for more than that it can be also solved hence high=mid-1;
else
​
low=mid+1;
solve(mid){
if count+1 (for the last case it will not be included) <=days. kaam mei ho jaa rha hai thoda jyda mei ho jaega.