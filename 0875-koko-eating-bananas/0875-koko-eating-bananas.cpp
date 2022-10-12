class Solution {
public:
    long solve(vector<int> &piles,int target,int n){
        long count=0;
        for(int i=0;i<n;i++){
            if(piles[i]%target==0){
                count+=(piles[i]/target);
            }
            else{
                count+=(piles[i]/target+1);
            }
        }
        return count;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=*max_element(piles.begin(),piles.end());
        int l=1;
        int r=maxi;
        int ans=maxi;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(solve(piles,mid,n)<=h){
                ans=mid;
                r=mid-1;  
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};