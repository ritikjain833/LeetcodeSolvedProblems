class Solution {
public:
    bool solve(int mid,int days,vector<int> &weights){
        int count=0;
        int running_sum=0;
        for(int i=0;i<weights.size();i++){
            running_sum+=weights[i];
            if(running_sum>mid){
                count+=1;
                running_sum=weights[i];
            }
        }
        if (count+1<=days){
            return true;
        }
        else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,days,weights)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};